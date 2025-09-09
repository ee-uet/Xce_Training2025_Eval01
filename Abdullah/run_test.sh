#!/bin/bash


EXEC=./bitops
PASS=0
FAIL=0

# Define test cases:
# num k expected_count expected_reversed expected_setbits expected_clearbits expected_power2
tests=(
  "0 1 0 0 2 0 0"
  "1 0 1 1 1 0 1"
  "2 0 1 1 3 2 1"
  "3 1 2 3 3 1 0"
  "4 2 1 1 4 0 1"
  "7 1 3 7 7 5 0"
  "8 3 1 1 8 0 1"
  "15 1 4 15 15 13 0"
  "16 4 1 1 16 0 1"
  "255 2 8 255 255 251 0"
  "4294967295 5 32 4294967295 4294967295 4294967291 0"
)

echo "Running tests..."

for t in "${tests[@]}"; do
  set -- $t
  num=$1
  k=$2
  expected_count=$3
  expected_reversed=$4
  expected_setbits=$5
  expected_clearbits=$6
  expected_power2=$7

  output=$($EXEC $num $k)

  # Extract actual values from program output
  out_count=$(echo "$output" | grep "The number of set bit" | awk '{print $NF}')
  out_reversed=$(echo "$output" | grep "Reversed number" | awk '{print $NF}')
  out_setbits=$(echo "$output" | grep "After Setting a specific bit" | awk '{print $NF}')
  out_clearbits=$(echo "$output" | grep "After Clearing a specific bit" | awk '{print $NF}')
  out_power2=$(echo "$output" | grep "Is power of two" | awk '{print $NF}')

  if [[ "$out_count" == "$expected_count" && \
        "$out_reversed" == "$expected_reversed" && \
        "$out_setbits" == "$expected_setbits" && \
        "$out_clearbits" == "$expected_clearbits" && \
        "$out_power2" == "$expected_power2" ]]; then
    echo "Test num=$num k=$k: PASS"
    ((PASS++))
  else
    echo "Test num=$num k=$k: FAIL"
    echo "  Expected: count=$expected_count reversed=$expected_reversed set=$expected_setbits clear=$expected_clearbits power2=$expected_power2"
    echo "  Got:      count=$out_count reversed=$out_reversed set=$out_setbits clear=$out_clearbits power2=$out_power2"
    ((FAIL++))
  fi
done

echo "Total Passed: $PASS"
echo "Total Failed: $FAIL"


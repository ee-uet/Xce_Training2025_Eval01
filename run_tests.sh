#!/bin/bash

EXE=./bitops
PASS=0
FAIL=0

# Test cases
tests=(
  "0 0 NOT"       
  "1 1 YES"       
  "2 1 YES"       
  "3 2 NOT"        
  "7 3 NOT"        
  "8 1 YES"       
  "15 4 NOT"      
)

for t in "${tests[@]}"; do
  set -- $t
  input=$1
  expected_bits=$2
  expected_power=$3

  output=$($EXE $input)

  # Extract results
  bits=$(echo "$output" | grep "No of set bits" | awk '{print $6}')
  power=$(echo "$output" | grep "power of 2" | awk '{print $(NF-2)}')

  if [[ "$bits" == "$expected_bits" && "$power" == "$expected_power" ]]; then
    echo "pass Input=$input"
    ((PASS++))
  else
    echo "Fail Input=$input (Expected bits=$expected_bits power=$expected_power)"
    echo "       Got: bits=$bits power=$power"
    ((FAIL++))
  fi
done

echo
echo "Summary: Passed=$PASS, Failed=$FAIL"
exit $FAIL

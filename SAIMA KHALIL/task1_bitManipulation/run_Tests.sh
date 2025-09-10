#!/bin/bash

EXE="./bitops"   # compiled C program ka naam

 
tests=(
  "5 1 3 1 | Count of set bits: 2"
  "8 0 2 3 | Is power of two: Yes"
  "10 1 1 3 | Number after toggling bit at position 1: 8"

  # countSetBits check
  "15 0 1 3 | Count of set bits: 4"   # 15 = 1111
  "16 0 0 4 | Count of set bits: 1"   # 16 = 10000

  # reverseBits check
  "1 0 0 0 | Reversed bits: 2147483648"  # bit-0 reversed to MSB
  "3 0 0 1 | Reversed bits: 3221225472"  

  # checkPowerOfTwo check
  "32 2 0 2 | Is power of two: Yes"   # 32 = 2^5
  "18 1 0 3 | Is power of two: No"    # not a power of two

  # setBitAtPositionK check
  "5 2 0 0 | Number after setting bit at position 2: 5"   # already 1
  "5 3 0 0 | Number after setting bit at position 3: 13"  # 0101 - 1101

  # clearBitAtPositionK check
  "7 1 0 0 | Number after clearing bit at position 1: 5"  # 0111 - 0101
  "7 2 0 0 | Number after clearing bit at position 2: 3"  # 0111 - 0011

  # toggleBitAtPositionK check
  "8 0 0 0 | Number after toggling bit at position 0: 9"  # 1000 - 1001
  "9 0 0 0 | Number after toggling bit at position 0: 8"  # 1001 - 1000

  # extractBitsInRange check
  "29 0 0 2 | Extracted bits from position 0 to 2: 5"   # 11101[4:0], get 101=5
  "29 0 2 4 | Extracted bits from position 2 to 4: 7"   # 11101[4:2] = 111 = 7
  "255 0 4 7 | Extracted bits from position 4 to 7: 15" # 11111111, bits[7:4]=1111=15
)

pass=0
fail=0
total=0

echo "Running tests."


for t in "${tests[@]}"; do
    ((total++))

  input=$(echo "$t" | cut -d'|' -f1)
  expected=$(echo "$t" | cut -d'|' -f2- | xargs) 

    # run program
    output=$($EXE <<< "$input")  

    echo "Test $total:"
    echo "Input   : $input"
    echo "Expected snippet: $expected"
    echo "Got output:"
    echo "$output"

    if echo "$output" | grep -q "$expected"; then  
        echo "Passed "
        ((pass++))
    else
        echo "Failed "
        ((fail++))
    fi
done 

echo "Summary Report"
echo "Total tests run : $total"
echo "Tests passed    : $pass"
echo "Tests failed    : $fail"

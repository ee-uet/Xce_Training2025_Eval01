#!/bin/bash

# Name of your compiled C program
EXE="./task1"

# Counters
pass=0
fail=0
total=0
# Order of inputs: num (set bit), bit (set bit), num2 (clear bit), bit2 (clear bit), num3 (toggle bit), bit3 (toggle bit), num4 (range), sbit, ebit
tests=(
"5 1 10 3 8 0 12 3 2"
"0 0 0 2 0 3 0 3 0"
"7 7 8 0 6 2 5 2 1"
"1 0 1 0 1 0 9 1 0"
"10 4 5 1 11 2 15 4 3"
)

echo "Running tests..."
echo "----------------------"

for t in "${tests[@]}"; do
    ((total++))
    # Split test case into individual inputs
    inputs=($t)
    
    # Run program with inputs fed via here-document
    output=$($EXE <<EOF
${inputs[@]}
EOF
)
    
    echo "Test $total:"
    echo "$output"
    echo "----------------------"
done

echo "Total tests run: $total"


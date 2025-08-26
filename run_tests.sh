#!/bin/bash

# This script assumes the program is already compiled by the Makefile
TARGET="./bitops"

# Check if executable exists
if [ ! -f "$TARGET" ]; then
    echo "Executable not found! Please run 'make build' first."
    exit 1
fi

echo "Running tests..."
echo "================="

# Test cases (pairs of a and b)
test_cases=(
    "0 0"
    "1 1"
    "2 2"
    "4 8"
    "10 9"
    "15 16"
    "85 170"
    "255 1"
)

pass=0
fail=0

for case in "${test_cases[@]}"; do
    echo "Test case: $case"
    output=$($TARGET $case)
    exit_code=$?
    
    # Check if program executed successfully (exit code 0)
    if [ $exit_code -eq 0 ]; then
        echo "PASS"
        ((pass++))
    else
        echo "FAIL"
        ((fail++))
    fi
    echo "Output:"
    echo "$output"
    echo "----------------------"
done

echo "Summary:"
echo "Passed: $pass"
echo "Failed: $fail"


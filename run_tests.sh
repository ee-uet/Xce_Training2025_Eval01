#!/bin/bash

SRC="bitops.c"
EXE="./bitops"

# Compile the C program
gcc -o "$EXE" "$SRC"
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

# test cases
declare -A tests
tests[0]="0"
tests[1]="1"
tests[2]="5"
tests[3]="8"
tests[4]="15"

# Expected outputs:
declare -A expected
expected[0]=$'0\n0\n0\n8\n0\n1\n0'          # for 0
expected[1]=$'1\n2147483648\n1\n9\n1\n0\n0' # for 1
expected[2]=$'2\n2684354560\n0\n13\n1\n4\n2' # for 5
expected[3]=$'1\n268435456\n1\n8\n8\n9\n4'   # for 8
expected[4]=$'4\n4026531840\n0\n15\n11\n14\n7' # for 15

pass_count=0
fail_count=0

echo "Running tests:"
echo 

for idx in $(seq 0 4); do
    num=${tests[$idx]}
    echo "Test #$idx Input: $num"

    output=$($EXE "$num")
    expected_vals="${expected[$idx]}"

    if [ "$output" == "$expected_vals" ]; then
        echo "PASS"
        ((pass_count++))
    else
        echo "FAIL"
        echo "Expected:"
        echo "$expected_vals"
        echo "Got:"
        echo "$output"
        ((fail_count++))
    fi
    echo
done

echo "Summary: $pass_count PASSED, $fail_count FAILED"

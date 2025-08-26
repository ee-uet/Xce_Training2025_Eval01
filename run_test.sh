#!/bin/bash
BIN="bitop.out"
tests=(
    "0 0 3"
    "1 0 0"
    "2 0 1"
    "31 0 4"
    "32 5 5"
    "255 0 7"
    "1023 5 9"
    "4294967295 0 31" 
    "2147483647 0 30"
    "123456789 4 12"
)

echo
echo "Running test cases..."
echo "===================="

for t in "${tests[@]}"; do
    num=$(echo $t | cut -d' ' -f1)
    m=$(echo $t | cut -d' ' -f2)
    n=$(echo $t | cut -d' ' -f3)

    echo -e "\n[Test] number=$num, m=$m, n=$n"
    echo -e "$num\n$m\n$n" | ./$BIN
done

echo
echo "All tests completed."


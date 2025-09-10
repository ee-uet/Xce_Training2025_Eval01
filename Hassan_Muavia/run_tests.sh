#!/bin/bash
gcc -o bitops bitops.c
inputs=(0 4294967295 1 2 4 8 16 2147483648 2863311530 1431655765 38)
pass=0; fail=0
for num in "${inputs[@]}"; do
  out=$(./bitops "$num")
    [[ $out ]] && ((pass++)) || ((fail++))
    done
    echo "$pass Passed / $fail"

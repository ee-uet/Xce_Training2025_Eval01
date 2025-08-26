
#!/bin/bash

# Compile the program
gcc -o bitops bitops.c
if [ $? -ne 0 ]; then
  echo "Compilation failed"
  exit 1
fi

echo "Compilation successful"

output=$(./bitops)

# Expected outputs 
expected1="set bits = 3"
expected2="reverse bits = 2147483648"
expected3="Ans=1"
expected4="after setting bit 1: 7"
expected5="after clearing bit 1: 5"
expected6="after toggling bit 1: 7"
expected7="extracted bits of 15 are 3"

pass=0
fail=0


check_line() {
  if echo "$output" | grep -q "$1"; then
    echo " PASS: $2"
    ((pass++))
  else
    echo " FAIL: $2"
    ((fail++))
  fi
}


check_line "$expected1" "Count set bits"
check_line "$expected2" "Reverse bits"
check_line "$expected3" "Check power of 2"
check_line "$expected4" "Set bit"
check_line "$expected5" "Clear bit"
check_line "$expected6" "Toggle bit"
check_line "$expected7" "Extract bits"



echo " Passed: $pass"
echo " Failed: $fail"

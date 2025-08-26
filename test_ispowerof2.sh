#1/bin/bash
PROG="./bitops" # Executable program

# Test cases: number and expected result (1 = power of 2, 0 = not)
declare -A tests=(
  [0]=0
  [1]=1
  [2]=1
  [3]=0
  [4]=1
  [5]=0
  [63]=0
  [64]=1
  [127]=0
  [128]=1
  [255]=0
  [0xAAAAAAAA]=0   # alternating 1010 pattern in hex (for 32-bit)
  [0x55555555]=0  # alternating 0101 pattern in hex (for 32-bit)
  [2147483648]=1  # 2^31, largest power of 2 for 32-bit unsigned int
)

pass=0
fail=0

for input in "${!tests[@]}"; do
  expected=${tests[$input]}
  output=$($PROG $input 2>/dev/null)
  if echo "$output" | grep -q "is power of 2"; then
    result=1
  else
    result=0
  fi

  if [ $result -eq $expected ]; then
    echo "PASS: Input=$input Output=\"$output\""
    ((pass++))
  else
    echo "FAIL: Input=$input Output=\"$output\" Expected=$expected"
    ((fail++))
  fi
done

echo "Test Summary: Passed=$pass, Failed=$fail"


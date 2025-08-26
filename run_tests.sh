#!/bin/bash

EXEC=./out
PASS=0
FAIL=0

EXPECTED=$'Set bits are 2\nAfter reversal new updated num is: 1342177280\nThe given number: 10 is not the power of 2\nupdated value after setting the bit at positon 1 is 10\nupdated value after clearing the bit at positon 1 is 8\nupdated value after toggling the bit at positon 2 is 14\nExtrating bits from n: 1 to m: 4 and the value is 5\n'

OUTPUT=$($EXEC)

clean() {
    echo "$1" | tr -d '\r' | sed 's/[ \t]*$//'
}

if [ "$(clean "$OUTPUT")" == "$(clean "$EXPECTED")" ]; then
    echo "Test: PASSED"
    ((PASS++))
else
    echo "Test: FAILED"
    echo "Expected:"
    echo "$EXPECTED" | od -c
    echo "Got:"
    echo "$OUTPUT" | od -c
    ((FAIL++))
fi

echo "Summary: $PASS Passed / $FAIL Failed"

#!/bin/bash

BITOPS="bitops"

# Test counter
TESTS_RUN=0
TESTS_PASSED=0

run_test() {
    local testcase=$1 # The operation to perform
    local expected=$2 # Reference output
    
    local arg1=$3 # The Number to perform operation on
    
    # The following may be either bit position
    # Or a range of bits to select from.
    local arg2=$4 
    local arg3=$5
    
    local result
    
    TESTS_RUN=$((TESTS_RUN + 1))
    
    if result=$(./"$BITOPS" "$testcase" "$arg1" "$arg2" "$arg3" ); then
    	if (( $result == $expected )) then
    	    echo "$testcase"
            TESTS_PASSED=$((TESTS_PASSED + 1))
        else
            echo "$test_name - Expected: $expected, Got: $result"
        fi
    else
        echo "$test_name - Script execution failed"
    fi
}

run_test 1 4 15
run_test 1 0 0
run_test 1 32 -1

run_test 2 0 0
run_test 2 0x3 0xC0000000
run_test 2 0x80000000 0x1
run_test 2 -1 -1

run_test 3 0 0
run_test 3 0 15
run_test 3 0 -15
run_test 3 1 14
run_test 3 1 -14

run_test 4 1 0 0
run_test 4 31 15 4
run_test 4 -1 -2 0

run_test 5 0 1 0
run_test 5 15 31 4
run_test 5 -2 -1 0

run_test 6 1 0 0
run_test 6 0 1 0

run_test 7 15 63 3 0
run_test 7 -2 -1 31 1

echo ""
echo "Tests run: $TESTS_RUN"
echo "Tests passed: $TESTS_PASSED"
echo "Tests failed: $((TESTS_RUN - TESTS_PASSED))"

if [ $TESTS_PASSED -eq $TESTS_RUN ]; then
    echo "All tests passed!"
    exit 0
else
    echo "Some tests failed!"
    exit 1
fi


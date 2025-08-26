#!/bin/bash
EXEC=./bittops
PASS=0
FAIL=0
run_test() {
    OP=$1
    INPUT=$2
    EXPECTED=$3
    shift 3
    OUTPUT=$($EXEC $OP $INPUT "$@")
    if [ "$OUTPUT" == "$EXPECTED" ]; then
        echo "[PASS HAPPYY HAPPYY HAPPYY] $OP $INPUT $@ -> $OUTPUT"
        PASS=$((PASS+1))
    else
        echo "[FAIL] $OP $INPUT $@ -> got $OUTPUT, expected $EXPECTED"
        FAIL=$((FAIL+1))
    fi
}
run_test c 0 0         
run_test c 15 4
run_test r 1 2147483648 
run_test p 16 1
run_test p 18 0
run_test s 8 12 2       
run_test l 15 11 2      # clear  2 -> 15-4=11
run_test t 8 12 2       # toggle 2 -> 12
#run_test e 29 3 0 3     
run_test e 29 13 0 3
echo "Summary>> Passed=$PASS, Failed=$FAIL"
exit $FAIL

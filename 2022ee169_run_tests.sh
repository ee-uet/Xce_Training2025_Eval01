in1=3
pos1=0
total=2
test_passed=0
test_failed=0
output=$(./2022ee169_bitop $in1 $pos1)
echo "running test on task6 (toggling bit)"
echo "togglig bit $pos1 of number $in1"
if [ "$output" = "2" ]; then
    echo "test passed"
    test_passed=$((test_passed + 1))
else
    echo "test failed"
    test_failed=$((test_failed + 1))
fi
in2=3
pos2=1
output=$(./2022ee169_bitop $in2 $pos2)
echo "running test on task6 (toggling bit)"
echo "togglig bit $pos2 of number $in2"
if [ "$output" = "1" ]; then
    echo "test passed"
    test_passed=$((test_passed + 1))
else
    echo "test failed"
    test_failed=$((test_failed + 1))
    
fi
echo "Summary"
echo "Total tests performed: $total"
echo "Tests passed: $test_passed"
echo "Tests passed: $test_failed"
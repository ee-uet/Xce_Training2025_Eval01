
                                                    TASK 1.1


1.... clear the rightmost set bit using n = n & (n-1) until n becomes 0 each iteration increments a counter
 making it O(num of 1s) instead of O(total bits).
Input: 15 (binary 1111)
15 & (15-1) = 15 & 14 = 14 > count = 1
14 & (14-1) = 14 & 13 = 12 > count = 2
12 & 11 = 8 > count = 3
8 & 7 = 0 > count = 4
Output== 4


2..... Iteratively shift the result left and add the least significant bit from the number then shift the number right by 1
Input: 1 (000...0001)
Initialize rev = 0
For 32 iterations, left-shift rev and add (n & 1)
After all iterations, rev = 2147483648 (100...0000)

3...... n > 0 && (n & (n-1)) == 0
number with exactly one set bit is a power of two subtracting 1 flips all bits below the set bit so n & (n-1) becomes 0 only for powers of two
Input: 16 (binary 10000)
Steps: 16 & (16-1) = 16 & 15 = 0 > ttrue
Input: 18 (10010) > 18 & 17 = 16 > false

4...... uusing OR with a mask ensures the k bit is set without changing other bits n | (1 << k)
Input: 8 (1000), set bit 2
Mask: (1 << 2) = 4 (0100)
8 | 4 = 12 (1100)
Output: 12 >>its  passed

5.......  i use theAND with the negated mask ensures the k bit will clear while other bits remain unchanged n & ~(1 << k)
Input: 15 (1111), clear bit 2
Mask: ~(1 << 2) = ~(0100) = 1011
1111 & 1011 = 1011 (11)
Output: 11 correct

6.......  XOR flips the k bit 1 becomes 0and 0 becomes 1 leaving others untouched  n ^ (1 << k) 
input: 8 (1000), toggle bit 2
mask: (1 << 2) = 4 (0100)
8 ^ 4 = 12 (1100)

7.......right-shifting aligns the desired bit range with the lsb Masking with (1 << width) - 1 isolates only those bitsnum >> m) & ((1 << (n - m + 1)) - 1)
input: 29 (11101), extract bits [3:0]
width = 3 - 0 + 1 = 4
mask = (1 << 4) - 1 = 15 (1111)
right-shift: 29 >> 0 = 11101
apply mask: 11101 & 1111 = 1101 (13)


                                                    TASK 1.2

I used same test case in the run_tests.sh 
the program is executed as: ./bittops s 8 2
$OP = s > set bit
$INPUT = 8 > num
"$@" = 12 2 > extra arguments
OUTPUT=$($EXEC $OP $INPUT "$@") ---->  argv[1] = operation c, r, etc..
argv[2] = number (converted to uint32_t)
argv[3] = bit positions or range

OUTPUT:
hamza-ahmad@hamza-ahmad-Lenovo-V14-G3-IAP:~/Downloads$ make test
./run_tests.sh
[PASS HAPPYY HAPPYY HAPPYY] c 0  -> 0
[PASS HAPPYY HAPPYY HAPPYY] c 15  -> 4
[PASS HAPPYY HAPPYY HAPPYY] r 1  -> 2147483648
[PASS HAPPYY HAPPYY HAPPYY] p 16  -> 1
[PASS HAPPYY HAPPYY HAPPYY] p 18  -> 0
[PASS HAPPYY HAPPYY HAPPYY] s 8 2 -> 12
[PASS HAPPYY HAPPYY HAPPYY] l 15 2 -> 11
[PASS HAPPYY HAPPYY HAPPYY] t 8 2 -> 12
[PASS HAPPYY HAPPYY HAPPYY] e 29 0 3 -> 13
Summary>> Passed=9, Failed=0



                                                    Task 1.3

make build compiles bittops.c into the executable bittops make test runs the Bash test script to check all operations and make clean removes the compiled executable

OUTPUT:
hamza-ahmad@hamza-ahmad-Lenovo-V14-G3-IAP:~/Downloads$ make clean
rm -f bittops
hamza-ahmad@hamza-ahmad-Lenovo-V14-G3-IAP:~/Downloads$ make build
gcc -Wall -O2 -o bittops bittops.c
hamza-ahmad@hamza-ahmad-Lenovo-V14-G3-IAP:~/Downloads$ make test
./run_tests.sh
[PASS HAPPYY HAPPYY HAPPYY] c 0  -> 0


                                                     Task 2
It stores n in memory and reserves an array to hold the results. The first two numbers are initialized, and a loop calculates each subsequent number by summing the previous two. Each new Fibonacci number is stored in the array, and the registers tracking the last two numbers are updated in every iteration. The program stops after computing all numbers, allowing you to inspect the array to see the complete Fibonacci sequence.

///////C code part///////

Part 1

The function of this task counts the number of set bits (1s) in the binary representation of a number. It continuously clears the rightmost set bit of n using the operation n&=(n-1) and increments the counter each time. It returns the total count, which represents how many 1s were present in n.

Part 2

The function of this task takes a 32-bit number and flips its bits in reverse order. It does this by taking the last bit of n one by one and adding it to reversed_n. In the end, it gives back the number with all bits reversed.

Part 3

This function checks if a number is a power of two. It returns true only when n is greater than zero and has exactly one bit set. If those conditions are not met, it returns false.

Part 4

This function sets a specific bit of a number to 1. It makes a mask by shifting 1 to the given bit position and then combines it with the number using OR. The result is the same number but with that bit turned on.

Part 5

This function clears a specific bit of a number to 0. It creates a mask at the given bit position, inverts it, and then ANDs it with the number. The result is the same number but with that bit turned off.

Part 6

This function flips a specific bit of a number. It makes a mask at the given bit position and then XORs it with the number. The result is the same number but with that bit switched (1 to 0 or 0 to 1).

Part 7

This function extracts a range of bits from a number. It first shifts the number right by m to align the target bits, then makes a mask for the range from m to n. Finally, it ANDs the shifted number with the mask and returns the extracted bits.

///////BASH part///////

The run_test.sh file is a simple automation script that saves me from compiling and running my C program manually every time. It starts by compiling the source code with gcc and stops right away if there’s any error. After that, it defines a bunch of test cases (numbers along with bit ranges) and loops through them one by one. For each case, the script pipes the input directly into the program, runs it, and prints the output so I can see the results clearly. This way, I don’t have to type inputs over and over, the bash script takes care of compiling, running, and feeding the values in the right order automatically.

///////Makefile work///////

The Makefile is set up to simplify building and testing the bit manipulation program. It defines three main targets: make build compiles the C source file (bitop.c) into the executable bitop.out with strict warnings enabled, make test first builds the program and then runs the run_test.sh script to automatically execute a series of predefined test cases, and make clean removes the compiled binary to reset the workspace.

///////Assembly code and spike use///////

Now the assembly is created in which there is fib_loop function that is called till 10 iterationns and then safely exit it using the given spike assembly in the class tasks.
log file is also generated using spike and all done...

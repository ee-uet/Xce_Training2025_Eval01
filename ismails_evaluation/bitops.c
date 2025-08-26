#include <stdio.h>
#include <stdlib.h>

int setbits(unsigned int n){
    
    // initializing counter
    int count = 0;

    // while loop
    while (n != 0){
        n = n & (n - 1); // clear lsb
        count++; // increment counter
    }
    return count;
}

unsigned int reversebits(unsigned int n){

    unsigned int result = 0; // stores reversed bits

    for (int i = 0; i < 32; i++){

        result = (result << 1) | (n & 1); // add last bit of n to result
        n = n >> 1; // right shift by 1

    }

    return result;

}

int powerof2(unsigned int n){

    // if n = 0, return false
    if (n == 0){
        return 0;
    }

    // if n!= 0 check and return true if power of 2 else false
    if ((n & (n - 1)) == 0){
        return 1;
    }
    else{
        return 0;
    }

}

unsigned int setbit(unsigned int n, int k){

    unsigned int mask = 1 << k; // left shift 1 by k (masking)
    n = n | mask; // take bitwise OR
    return n;

}

unsigned int clearbit(unsigned int n, int k){

    unsigned int mask = ~(1 << k); // left shift 1 by k with negation (masking)
    n = n & mask; // take bitwise AND
    return n;

}

unsigned int togglebit(unsigned int n, int k){

    unsigned int mask = 1 << k;  // left shift 1 by k (masking)
    n = n ^ mask; // take XOR 
    return n;
}

unsigned int rangeofbits(unsigned int n, int m, int l){

    int width = m - l + 1; // range calculation
    unsigned int mask = (1 << width) - 1; // masking for the range
    return (n >> l) & mask; // shift right AND mask

}

int main(int argc, char *argv[]) {
    
    unsigned int num = 5; // default case hardcoded
    if (argc > 1) {
        num = atoi(argv[1]); // convert string to int
    }

    printf("%d\n", setbits(num));
    printf("%u\n", reversebits(num));
    printf("%d\n", powerof2(num));
    printf("%u\n", setbit(num, 3));
    printf("%u\n", clearbit(num, 2));
    printf("%u\n", togglebit(num, 0));
    printf("%u\n", rangeofbits(num, 4, 1));


    return 0;

}


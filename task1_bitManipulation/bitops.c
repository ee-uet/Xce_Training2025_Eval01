//Implement a C program that performs the following bit-level operations on 32-bit unsigned integers:
//1-Count number of set bits (1s) – using an optimized method .
//2-Reverse all bits of the number
//3-Check if the number is a power of two (using n & (n-1) trick).
//4-Set a specific bit at position k.
//5-Clear a specific bit at position k.
//6-Toggle a specific bit at position k
//7-Extract a range of bits between positions [m:n]

#include <stdio.h>
#include <stdint.h>
 
//1- Function to count set bits  
unsigned int countSetBits(uint32_t n) {
    unsigned int count = 0;
    while (n) {
        n &= (n - 1); // Clearing the least significant bit set
        count++;
    }
    return count;
}

//2-function for reversing the bits
int reverseBits(int num) {
    int reversed = 0;
    for (int i = 0; i < 32; i++) {
        reversed <<= 1; // Shift reversed to left to make space for next bit 
        reversed |= (num & 1); // Add the least significant bit of num to reversed
        num >>= 1; // Shift num to right to process the next bit
    }
    return reversed;
}
//3-function to check if number is power of 2
void checkPowerOfTwo(int num) { 
    if (num > 0 && (num & (num - 1)) == 0) { // 4 is a power of 2 because 4 & (4-1) = 0 ie 0100 & 0011 = 0000
        printf("%d is a power of 2.\n", num);
    } else {
        printf("%d is not a power of 2.\n", num);
    }
} 
//4-function to set a specific bit at position k
void setBitAtPositionK(uint32_t *num, int k) {
    if (k < 0 || k >= 32) {
        printf("Error ,the  bit position must be between 0 and 31.\n");
        return;
    }
    printf("Original number is : %u\n", *num);
    *num |= (1 << k); 
    // Set the k-th bit, first do left shift 1 by k positions then do bitwise or with num,eg agr num=5(0101) and k=1 then 1<<1=0010 yani 0101 | 0010 = 0111=7 
    printf("Number after setting bit at position %d: %u\n", k, *num);
}
//5-function to clear a specific bit at position k
void clearBitAtPositionK(uint32_t *num, int k) {
     if (k < 0 || k >= 32) {
        printf("Error ,the  bit position must be between 0 and 31.\n");
        return;
    }
    printf("Original number is : %u\n", *num);
    *num &= ~(1 << k); 
    // Set the k-th bit, first do left shift 1 by k positions then do bitwise OR with num,eg agr num=5(0101) and k=1 then 1<<1=0010 yani 0101 | ~(0010) to ans miljaeyga 
    printf("Number after clearing bit at position %d: %u\n", k, *num);
    }
//6-function to toggle a specific bit at position k
void toggleBitAtPositionK(uint32_t *num, int k) {
        if (k < 0 || k >= 32) {
            printf("Error ,the  bit position must be between 0 and 31.\n");
            return;
        }
        printf("Original number is : %u\n", *num);
        *num ^= (1 << k); // Toggle the k-th bit, first do left shift 1 by k positions then do bitwise XOR with num,eg agr num=5(0101) and k=1 then 1<<1=0010 yani 0101 ^ 0010 = 0111=7 
        printf("Number after toggling bit at position %d: %u\n", k, *num);
    }
//7-function to extract a range of bits between positions [m:n] and then  displaying those bits as a decimal number
void extractBitsInRange(uint32_t num, int m, int n) {
    if (m < 0 || n >= 32 || m > n) {
        printf("Error, bit positions must be between 0 and 31 also m should be less than or equal to n.\n");
        return;
    }
    uint32_t mask = ((1 << (n - m + 1)) - 1) << m; // Create a mask with bits from m to n set to 1 , (n - m + 1) means number of bits to be extracted , then left shift by m to align the mask with the desired bit positions
    uint32_t extracted = (num & mask) >> m; // Apply mask and right shift to get the bits in the least significant positions
    printf("Extracted bits from position %d to %d: %u\n", m, n, extracted);
}
int main() {
    uint32_t num1;
    int m, n;
    int k;

    printf("Enter a 32-bit unsigned integer: ");
    scanf("%u", &num1);
    
    unsigned int setBits = countSetBits(num1);
    printf("Number of set bits: %u\n", setBits);

    int reversed = reverseBits(num1);
    printf("Reversed bits: %u\n", reversed);

    checkPowerOfTwo(num1);
 
    printf("Enter the bit position to set (0-31): ");
    scanf("%d", &k);
    setBitAtPositionK(&num1, k);

    clearBitAtPositionK(&num1, k); 

    toggleBitAtPositionK(&num1, k);

    printf("Enter the range of bit positions to extract (m n) m<n and m,n between 0-31: ");
    scanf("%d %d", &m, &n);
    extractBitsInRange(num1, m, n); 

  

    return 0;
}
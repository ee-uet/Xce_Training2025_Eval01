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
uint32_t reverseBits(uint32_t num) {
    uint32_t reversed = 0;
    for (int i = 0; i < 32; i++) {
        reversed <<= 1; // Shift reversed to left to make space for next bit 
        reversed |= (num & 1); // Add the least significant bit of num to reversed
        num >>= 1; // Shift num to right to process the next bit
    }
    return reversed;
}

//3-function to check if number is power of 2
void checkPowerOfTwo(uint32_t num) { 
    if (num > 0 && (num & (num - 1)) == 0) { // 4 is a power of 2 because 4 & (4-1) = 0 ie 0100 & 0011 = 0000
        printf("Yes\n");
    } else {
        printf("No\n");
    }
} 

//4-function to set a specific bit at position k
uint32_t setBitAtPositionK(uint32_t num, int k) {
    // Set the k-th bit, first do left shift 1 by k positions then do bitwise or with num, eg if num=5(0101) and k=1 then 1<<1=0010 yani 0101 | 0010 = 0111=7 
    return num | (1U << k);
}

//5-function to clear a specific bit at position k
uint32_t clearBitAtPositionK(uint32_t num, int k) {
    // Clear the k-th bit, first do left shift 1 by k positions then do bitwise OR with num, eg if num=5(0101) and k=1 then 1<<1=0010 yani 0101 & ~(0010) = 0101 & 1101 = 0101
    return num & ~(1U << k);
}

//6-function to toggle a specific bit at position k
uint32_t toggleBitAtPositionK(uint32_t num, int k) {
    // Toggle the k-th bit, first do left shift 1 by k positions then do bitwise XOR with num, eg if num=5(0101) and k=1 then 1<<1=0010 yani 0101 ^ 0010 = 0111=7 
    return num ^ (1U << k);
}

//7-function to extract a range of bits between positions [m:n]
uint32_t extractBitsInRange(uint32_t num, int m, int n) {
    // Create a mask with bits from m to n set to 1, (n - m + 1) means number of bits to be extracted , then left shift by m to align the mask with the desired bit positions
    uint32_t mask = ((1U << (n - m + 1)) - 1) << m; 
    return (num & mask) >> m; // Apply mask and right shift to get the bits in the least significant positions
}
int main() {
    uint32_t num;
    int k, m, n;

    printf("Enter a number, bit position k, start position m and end position n: ");
    scanf("%u", &num);
    scanf("%d", &k);
    scanf("%d %d", &m, &n);

    printf("Count of set bits: %u\n", countSetBits(num));
    printf("Reversed bits: %u\n", reverseBits(num));
    printf("Is power of two: ");
    checkPowerOfTwo(num);

    uint32_t setNum = setBitAtPositionK(num, k);
    uint32_t clearedNum = clearBitAtPositionK(num, k);
    uint32_t toggledNum = toggleBitAtPositionK(num, k);
    uint32_t extracted = extractBitsInRange(num, m, n);

    printf("Number after setting bit at position %d: %u\n", k, setNum);
    printf("Number after clearing bit at position %d: %u\n", k, clearedNum);
    printf("Number after toggling bit at position %d: %u\n", k, toggledNum);
    printf("Extracted bits from position %d to %d: %u\n", m, n, extracted);

    return 0;
}

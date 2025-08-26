#include <stdio.h>
#include <stdint.h>

unsigned int CountSetBits(unsigned int n) {
    unsigned int count = 0;

    while (n > 0) {
        n &= (n - 1); 
        count++;
    }
    return count;
}
uint32_t reverseBits(uint32_t n) {
    uint32_t reversed_n = 0;
    int i;

    for (i = 0; i < 32; i++) {
        reversed_n <<= 1;

        if (n & 1) {
            reversed_n |= 1;
        }
        n >>= 1;
    }
    return reversed_n;
}
uint32_t isPowerOfTwo(uint32_t n) {
    return (n>0) && ((n & (n-1)) == 0);
}
uint32_t set_bit(uint32_t number, uint8_t bit_position) {
    uint32_t mask = (1U << bit_position);
    return number | mask; 
}
uint32_t clear_bit(uint32_t number, uint8_t bit_position) {
    uint32_t mask_bit = (1U << bit_position);
    uint32_t inverted_mask = ~mask_bit;
    return number & inverted_mask;
}
uint32_t toggle_bit(uint32_t number, uint8_t bit_position) {
    uint32_t mask = (1U << bit_position);
    return number ^ mask;
}
unsigned int extract_bits(unsigned int num, int m, int n) {
    if (m < 0 || n > 31 || m > n) {
        printf("Invalid bit range.\n");
        return 0;
    }
    unsigned int shifted_num = num >> m;
    unsigned int mask = (1U << (n - m + 1)) - 1;
    unsigned int extracted_bits = shifted_num & mask;
    return extracted_bits;
}


int main() {
    uint32_t my_number = 0;
    uint32_t number = 0;
    printf("Enter the number you want to test all these things: \n");
    if (scanf("%u", &number) != 1) return 1;

    printf("Original number: %u\n", number);

    //TODO: Part 1 for bit set count
    printf("Number of set bits in %u is: %u\n", number, CountSetBits(number));

    //TODO: Part 2 for bit reverse

    uint32_t reversed_number = reverseBits(number);

    printf("Reversed bits: %u\n", reversed_number);

    //TODO: Part 3 for power check

    if (isPowerOfTwo(number)){
        printf("Number %u is the power of 2\n", number);
    }
    else{
        printf("Number %u is not the power of 2\n", number);
    }

    //TODO: Part 4 SEt a specific bit
    my_number = set_bit(number, 5);
    printf("Number after setting bit 5: 0x%08X or %u\n", my_number, my_number);

    //TODO: Part 5 clear a specific bit
    my_number = clear_bit(number, 5);
    printf("Number after clearing bit 5: 0x%08X or %u\n", my_number, my_number);

    //TODO: Part 5 toggle a specific bit
    my_number = toggle_bit(number, 5);
    printf("Number after toggling bit 5: 0x%08X or %u\n", my_number, my_number);

    //TODO: Part 6 extracting a range of bits
    int m = 0;
    printf("Enter the starting bit of the range:\n");
    if (scanf("%d", &m) != 1) return 1; 
    int n = 3;
    printf("Enter the ending bit of the range:\n");
    if (scanf("%d", &n) != 1) return 1;
    unsigned int result = extract_bits(number, m, n);
    printf("Extracted bits [%d:%d]: 0x%X\n", m, n, result);

    return 0;
}
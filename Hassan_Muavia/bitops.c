#include <stdio.h>
#include <stdint.h>

int count_set_bits(uint32_t n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

uint32_t reverse_bits(uint32_t n) {
    uint32_t rev = 0;
    for (int i = 0; i < 32; i++) {
        rev <<= 1;
        rev |= (n & 1);
        n >>= 1;
    }
    return rev;
}

int is_power_of_two(uint32_t n) {
    return n && !(n & (n - 1));
}

uint32_t set_bit(uint32_t n, unsigned int k) {
    return n | (1 << k);
}

uint32_t clear_bit(uint32_t n, unsigned int k) {
    return n & ~(1 << k);
}

uint32_t toggle_bit(uint32_t n, unsigned int k) {
    return n ^ (1 << k);
}
uint32_t extract_bits(uint32_t n, unsigned int m, unsigned int n_pos) {
    unsigned int width = n_pos - m + 1;
    uint32_t mask = ((1 << width) - 1) << m;
    return (n & mask) >> m;
}

int main() {
    uint32_t num = 38; 

    printf("Number: %d\n", num);
    printf("Set bits: %d\n", count_set_bits(num));
    printf("Reversed bits: %d\n", reverse_bits(num));
    printf("Is power of two: %s\n", is_power_of_two(num) ? "Yes" : "No");
    printf("Set bit 5: %d\n", set_bit(num, 5));
    printf("Clear bit 5: %d\n", clear_bit(num, 5));
    printf("Toggle bit 5: %d\n", toggle_bit(num, 5));
    printf("Extract bits [8:15]: %d\n", extract_bits(num, 3, 6));

    return 0;
}
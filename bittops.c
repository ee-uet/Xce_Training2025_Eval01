#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>   
#include <stdbool.h>  
int count(uint32_t n) {//1
    int c = 0;
    while (n) {
        n &= (n - 1); c++;
    }
    return c;}
//2
uint32_t rev(uint32_t n) {
    uint32_t r = 0;
    for (int i = 0; i < 32; i++) {r <<= 1;
        r |= (n & 1);
        n >>= 1;
    }
    return r;}
//3
bool ispower(uint32_t n) {
    return (n > 0) && ((n & (n - 1)) == 0);}
//4
uint32_t setbit(uint32_t n, int k) {
    return n | (1U << k);}

//55
uint32_t clearbit(uint32_t n, int k) {
    return n & ~(1U << k);}

//6
uint32_t togglebit(uint32_t n, int k) {
    return n ^ (1U << k);}

//7
unsigned int extract(unsigned int num, int m, int n) {
    unsigned int shift = num >> m;
    unsigned int mask = (1U << (n - m + 1)) - 1;
    unsigned int ext = shift & mask;
    return ext;}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("ussage: %s <operation> <number> [args]\n", argv[0]);
        return 1;
    }

    char op = argv[1][0];
    uint32_t num = (uint32_t) strtoul(argv[2], NULL, 0);
    switch (op) {
        case 'c': printf("%d\n", count(num));
            break;
        case 'r': printf("%u\n", rev(num));
            break;
        case 'p': printf("%d\n", ispower(num));
            break;
        case 's': printf("%u\n", setbit(num, atoi(argv[3])));
            break;
        case 'l': printf("%u\n", clearbit(num, atoi(argv[3])));
            break;
        case 't': printf("%u\n", togglebit(num, atoi(argv[3])));
            break;
        case 'e': printf("%u\n", extract(num, atoi(argv[3]), atoi(argv[4])));
            break;
        default: printf("correct operation daloo\n");
    }

    return 0;
}

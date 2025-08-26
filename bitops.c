#include <stdio.h>
#include <stdlib.h>


// Applying kernighan's Algorithm
unsigned int countSetBits(int n)
{
    unsigned int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}
void reverse( ) {
    int a = 12;
    printf("~a = %u\n", ~a);  // Reversing number
}
void ispowerof2(int a) {
    if ((a > 0) && ((a & (a - 1)) == 0)) {
        printf("%d is power of 2\n", a);    
        // let int=8 ,1000 & 0111 = 0000 
    } 
    else {
        printf("%d is not a power of 2\n", a);
    } 
}
void setbit(int bit_num) {
    unsigned int a = 33; // 1000001, 37 = 1000101  
    unsigned int mask = 1 << (bit_num - 1);
    a = a | mask;
    printf("%d\n", a); 
}
void clearbit(int bit_num) {
    unsigned int a = 37; // 1000001, 37 = 1000101  
    unsigned int mask = 1 << (bit_num - 1);
    mask = ~mask;
    a = a & mask;
    printf("%d\n", a); 
}
void range_of_bits()
{
    unsigned int num = 103; // 01100111 
    unsigned int start = 4, end = 6;

    // Creating mask
    unsigned int mask = 0;
    for (unsigned int i = start; i <= end; i++) {
        mask = mask | (1 << i);
    }
    unsigned int extracted_bits = (num & mask) >> 4; 
    // Extracted the bits using AND and right shift
    printf("Extracted Bits: %u\n", extracted_bits);
}

void toggleBit(int Number, int bit_num) {
  
    // Bitwise XOR with the mask
    int a = Number ^ (1 << (bit_num - 1));
    printf("after toggling, number is: %d\n", a);
}

/*int main () {
    // printf("No. of bits in %d are = %d\n", a, countSetBits(a));
    // reverse();
    // ispowerof2(7);
    // setbit(3); // 33 = 1000001: set 3rd bit -> 37 = 1000101
    // clearbit(3);  // 37 = 1000101: set 3rd bit -> 33 = 1000001
    // toggleBit(37, 3);  // 37 = 1000101: 3rd bit toggled -> 33 = 1000001
    range_of_bits();
}*/
int main(int argc, char *argv[]) {
    if (argc < 2) return 1;           // If no argument, exit with error
    int num = atoi(argv[1]);          // Convert input string to int
    ispowerof2(num);                  // Call your function
    return 0;
}
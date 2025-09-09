#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int count_set_bits(int num){ 
    // counts the set bits in 'num'
    int count = 0;
    while(num>0){
        num = num & (num -1);
        count++;
    }
    return count;
}


int reverse_bits(int num) {
    unsigned int reversed = 0;
    while (num > 0) {
        reversed = (reversed << 1) | (num & 1);
        num >>= 1;
    }
    return reversed;
}


/*
int reverse_bits(int num){
    //reverses all the bits of 'num'
    unsigned int reversed = 0;
    while(num > 0){
        reversed = (reversed << 1) | (num & 1);
        num >>= 1;
    }
    return reversed;
}
    */

int is_power_of_two(int num) {
    // checks if 'num' is a power of two
    return (num && !(num & (num - 1)));
}

int set_bit(int num, int k){
    // set a specific bit at 'k'
    num |= (1 << k);
    return num;
}



int clear_bit(int num, int k){
    // clear a specific bit at 'k'
    num &= ~(1 << k);
    return num;
}




int toggle_bit(int num, int k){
    // toggle a specific bit at 'k'
    /*
    if (num & (1 << k)){
        num &= ~(1 << k);
        printf("Cleared bit at %d\n", k);
        return num;
    }
    else{
        num |= (1 << k);
        printf("Set bit at %d\n", k);
        return num;
    }*/
    num = num ^ (1 << k);
    return num;
}




int extract_range(int num, int range[2]){
    // Extract specific range of bits in 'num'
    int start = range[0];
    int end = range[1];
    int extract = 0;
    while (end > start) {
        extract |= (1 << start);
        extract <<= 1;
        start++;
        end--;
    }
    return extract;
}






int main(int argc, char *argv[]) {
    //take a 32-bit unsigned 'num'
    unsigned int num = (unsigned int)atoi(argv[1]);
    //printf("Enter the number: ");
    //scanf("%u", &num);

    int set_bits = count_set_bits(num); //count set bits
    unsigned int reversed_number = reverse_bits(num); //reverse bits
    int power_of_two = is_power_of_two(num); //check if power of 2
    int set_number = set_bit(num,atoi(argv[2])); // set a specific bit
    int extracted = extract_range(num, (int[]){1,2}); // extract a specific range




    printf("The number of set bit in %d: %d\n", num, set_bits);
    printf("Reversed number: %u\n", reversed_number);
    printf("Is power of two: %d\n", power_of_two);
    printf("After Setting a specific bit: %u\n", set_number);
    printf("After Clearing a specific bit: %u\n", clear_bit(num, atoi(argv[2])));
    printf("After Toggling a specific bit: %u\n", toggle_bit(num, atoi(argv[2])));
    printf("After Toggling a specific bit: %u\n", toggle_bit(num, atoi(argv[2])));
    printf("Extracted bits: %u\n", extracted);
    return 0;
}


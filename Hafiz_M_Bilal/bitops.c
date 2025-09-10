#include <stdio.h>
#include <stdbool.h>


bool is_power_of_two(int n){
    return (n > 0) && ((n & (n - 1)) == 0);
}
   

int main(){

    //Count number of set bits (1s) using Kernighan’s algorithm
    int count = 0;
    int N = 7; // Number
    int revse = ~N; // to be reverse
    while(N != 0){
        N = N & (N-1);
        count +=1;
    }
    printf("No of set bits: %d\n",count);
    

    //Reverse all bits of the number
    printf("Reverse all bits of 7 is %d",revse);

    //Check if the number is a power of two
    int num = 7;
    printf("\n");

    if (is_power_of_two(num))
        printf("%d is a power of 2\n", num);
    else
        printf("%d is NOT a power of 2\n", num);
    

    //Set a specific bit at position k
    int num1 = 0;
    printf("Set a specific bit of %d at position 4 is: ",num1);
    printf("%d\n",num1 | 0x8);

    //Clear a specific bit at position k
    int num2 = 8;
    printf("Clear a specific bit of %d at position 4 is: ",num2);
    printf("%d\n",num2 & 0x0);

    //Toggle a specific bit at position k
    int num3 = 5;
    printf("Toggle a specific bit of %d at position 3 is: ",num3);
    printf("%d\n",num3 & 0xb);

    //Extract a range of bits between positions [m:n]
    int num4 = 31;
    printf("Extract a range of bits from 4 to 1 in number %d is: ",num4);
    printf("%d\n",num4 & 0x1e);


    return 0;
}
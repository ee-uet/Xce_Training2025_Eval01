#include <stdio.h>

void count1(int number){

    int count = 0;
    int temp = number;
    while (temp != 0) {
        temp = temp & (temp - 1);
        count++;
    }
    printf("Total number of 1's = %d",count);
    printf("\n");

}

void reverse(int number){
       int n = 32; // for 32 bit number
       int number1,LSB;
       for ( int i = 0; i<n; i++){
        LSB = number & 1; //extract LSB
        number1 = (number1 << 1) | LSB;
        number = number >> 1;
       }
       printf("Reverse number = %d\n",number1);
}

int poweroftwo (int i) {
 if (i<=0) {
    return 0;
}
   return (i & (i-1)) == 0;
}

int set_clear() {
    int set;
    int clear;
    int a,b;
    int result1,result2;
    
    printf("Enter value of a:\n");
    scanf("%d",&a);
    printf("Enter value of b:\n");
    scanf("%d",&b);
    printf("Enter set bit position :\n");
    scanf("%d",&set);
    printf("Enter clear bit position :\n");
    scanf("%d",&clear);

    // Set bit
    result1 = a | (1 << set);

    // Clear bit
    result2 = b & ~(1 << clear);

    printf("Final answer after setting bit = %d\n",result1);
    printf("Final answer after clearing bit = %d\n",result2);

    return 0;
}

int toggle(){

    int set,number,i,result;
    printf("Enter number:\n");
    scanf("%d",&number);
    printf("Enter set bit position :\n");
    scanf("%d",&set);
    i  = set << 1;
    number = number ^ i;
    printf("After toggle a specific bit = %d\n",number);
    return 0;
}
int extract_bits() {

    int number,start,end,bit,temp,extracted_bits;
    printf("Enter number:\n");
    scanf("%d",&number);
    printf("Enter starting bit:\n");
    scanf("%d",&start);
    printf("Enter ending bit:\n");
    scanf("%d",&end);
    bit = 0;
    bit = (end - start + 1) ;
    temp = ( 1 >> bit) - 1;
    number = (number >> start) & temp;

    printf("Extracted number = %d\n",number);
    return 0;
}
int main() {
     
   
    //printf("Count number of set bits:\n");
    //int number;
   // printf("Enter number:");
    //scanf("%d",&number);
    //count1(number);
    //printf("\n");
    //printf("Reverse all the bits\n");
    //int number1;
    //printf("Enter number:");
    //scanf("%d",&number1);
    //reverse(number1);
    //printf("\n");
    //printf("Check if number if power of 2:\n");
    //if (poweroftwo(13)){
      //  printf("Number is power of 2\n");
    //}
    //else {
      //  printf("number is not power of 2\n");
    //}
    //set_clear();
    //toggle();
    extract_bits();
}
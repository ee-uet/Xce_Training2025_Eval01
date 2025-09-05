#include <stdio.h>
#include <stdlib.h>
void num_of_setbits(int number){
    
    int sum = 0;
    int result = 0;

    for(int i=0 ;i < 32 ;i++){
        
        result = (number & (1<<i));
        result = result >> i;
        //printf("%d\n", result);
        if(result == 1){
            sum = sum + result;
        }
    }
    printf("number of set bits are: %d\n", sum);
}

void reverse_bits(int number){
    int j = 31;
    int lower_bit;
    unsigned int upper_bit;
    for(int i=0; i<16; i++){
        lower_bit = number & (1<<i);
        upper_bit = ((unsigned int) (2147483648>>i)) & number;
        lower_bit = lower_bit >> i;
        lower_bit = lower_bit << j;
        upper_bit = upper_bit << i;
        upper_bit = ((unsigned int)(upper_bit>>j));
        number = number & ~(1<<i);
        number = number & ~(1<<j);
        number = number | lower_bit;
        number = number | upper_bit;
        j--;
    }
    printf("%d\n", number);
} 

void check_powerof2(void){
    int n;
    int a=1;
    printf("Enter a number: ");
    scanf("%d",&n);
    int check = 0;
    while(a<=n){
        if(a==n){
            printf("entered number is a power of 2");
            check = 1;
        }
        a = a<<1;
       
    }
    if(check == 0){
    printf("entered number is not a power of 2");
    }
}
void set_bit(void){
    
    int number = 3;
    printf("setting bit in number = %d:\n", number);
    int k;
    int set;
    printf("enter bit position to set: ");
    scanf("%d", &k);
    set = (1<<k);
    number = number | set;
    printf("result = %d\n", number);
}
void clear_bit(void){
    int number = 3;
    printf("clearing bit in number = %d\n", number);
    int k;
    int clear;
    printf("enter bit position to clear: ");
    scanf("%d", &k);
    clear = ~(1<<k);
    number = number & clear;
    printf("result = %d\n", number);
}
void toggle_bit(int argc, char *argv[]){
    int number  = atoi(argv[1]);
     //printf("toggling bit in number = %d\n", number);
    int k = atoi(argv[2]);
    int pos;

    //printf("enter bit position to toggle: ");
    //scanf("%d", &k);
    pos = (1<<k);
    pos = pos & number;
    pos = pos >> k;
    if (pos == 1){
        pos = ~(1<<k);
        number = number & pos;
    }
    else{
        pos = (1<<k);
        number = number | pos;
    }
    printf("%d", number);

}


int main(int argc, char *argv[]){

    //num_of_setbits(3);
    //reverse_bits(3);
    //check_powerof2();
    //set_bit();
    //clear_bit();
    toggle_bit(argc, argv);


    
    
}
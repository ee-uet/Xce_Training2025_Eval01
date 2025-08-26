#include <stdio.h>
#include <stdlib.h>

//task#01
void bit_ope (int x){
    unsigned int count=0;
    while(x>0){
        x=x&(x-1);
        count++;
    }
    printf("Set bits are : %d\n",count);
}

//task#02
void reverse_bits(int x) {
    int q=x, rem, result=0;
    while(q!=0){
        rem=q%10;
        result=result*10+rem;
        q=q/10;
    }
    printf("Reversed number is : %d\n",result);
}

//task#03
void power_of_2(int x){
    int result=(x>0) && ((x&(x-1))==0);
    if(result) printf("Yes x is power of 2\n");
    else printf("NO x is not power of 2\n");
}

//task#04
void set_bit_at_position(int y ) {
    int pos=1;
    int mask=1<<pos;
    y=y|mask;
    printf("After setting %d position bit of y result is : %d\n",pos,y);
}

//task#05
void clear_a_specific_bit(int y){
    int pos=1;
    int mask=~(1<<pos);
    y=y&mask;
    printf("After clearing %d position bit of y result is : %d\n",pos,y);
}

//task#06
void togglinh_specific_bit(int y){
    int pos=2;
    int mask=1<<pos;
    y = y^mask;
    printf("After toggling %d position bit of y result is : %d\n",pos,y);
}

//task#07
void extractio_of_bits (int y){
    int pos=2;
    int length=3;
    int mask=(1<<length)-1;
    int extracted_bits=(y>>pos) & mask;
    printf("Extracted bits are : %d\n",extracted_bits);
}

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Usage: %s <a> <b>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    printf("Testing with a=%d, b=%d\n", a, b);
    power_of_2(b);
    set_bit_at_position(a);
    clear_a_specific_bit(a);
    togglinh_specific_bit(b);
    extractio_of_bits(a);
    reverse_bits(b);
    bit_ope(a);
    bit_ope(b);
    return 0;
}

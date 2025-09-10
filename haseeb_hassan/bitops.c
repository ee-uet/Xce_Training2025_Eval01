#include <stdio.h>
#include <stdint.h>

int count_set_bits(int num){
    int32_t Q = num;
    int count = 0;
    for (int i =0;i<=31;i++){
        if (((Q >> i)& 1) == 1 ){
            count += 1;

        }

        
    }
    return count;
}
unsigned int reverse_bits (int num){
    unsigned int  result = 0;
    unsigned int  Q = num;
    for(int i =0;i<32;i++){
        result = result << 1;
        result = result | (Q & 1);
        Q = Q >> 1;

    }
    return result;

}
int check_power_2(int num){
    if ((num & (num - 1)) == 0){
        return 1;
    }
    else 
        return 0;
    
}

int set_specific_bit(int num,int k){
    num = num | (1 << k);

    return num;
}
int clear_specific_bit(int num,int k){
    num = num & ~(1 << k);
    return num;

}
int toggle_specific_bit(int num,int k)
{
    num = num ^ (1 << k);
    return num;

}
int range_of_bits(int num,int start_bit,int last_bit){
    int extracted_bits = last_bit - start_bit + 1;
    num = num >> start_bit;
    int temp = (1 << extracted_bits) -1;
    num = num & temp;
    return num;

}
int main(){
    int number = 7;
    int set_bits = count_set_bits(number);
    printf("set bits = %d \n",set_bits);

    unsigned int number1 = 1;
    unsigned int revers_bits = reverse_bits(number1);
    printf("reverse bits = %u \n",revers_bits);

    int number2 = 8;
    int result = check_power_2(number2);
    printf(" ans = 1 means yes it is power of 2 lets check ans \n Ans=%d \n",result);

    //setting,clearing and toggling bit
    int number3 = 5;
    int bit_pos =1;
    int set_result = set_specific_bit(number3,bit_pos);
    int clear_result = clear_specific_bit(number3,bit_pos);
    int toggle_result = toggle_specific_bit(number3,bit_pos);
    printf("after setting bit %d: %d\n", bit_pos, set_result);
    printf("after clearing bit %d: %d\n", bit_pos, clear_result); 
    printf("after toggling bit %d: %d\n", bit_pos, toggle_result);


    //range of bits
    int number4 = 15;
    int n= 2;
    int m = 6;
    int result1 = range_of_bits(number4,n,m);
    printf("extracted bits of %d are %d \n",number4,result1);

    return 0;
}
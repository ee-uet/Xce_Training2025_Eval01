#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

void count(unsigned int num)
{
    int n = 32;
    int count = 0;
    while(n>0)
    {
        if(num & 0x1)
        {
            count+=1;
        }
        num = num >> 1; 
        n--;
    }
    printf("Set bits are %d\n", count);
}
void rev(unsigned int num)
{
    unsigned int rev = 0;
    int n = 32;

    for (int i = 0; i < n; i++) 
    {
        if (num & (1 << i)) 
        {
            rev |= 1 << (n - 1 - i);
        }
    }

    printf("After reversal new updated num is: %d\n", rev);
}
void pow_2(unsigned int num)
{
    if ( (num & (num-1)) == 0)
    {
        printf("The given number: %d is power of 2\n",num);
    } 
    printf("The given number: %d is not the power of 2\n",num);
}
void set_bit(unsigned int num,int k)
{  
    num = num | (1 << k);
    printf("updated value after setting the bit at positon %d is %d\n", k, num);
}
void clear_bit(unsigned int num,int k)
{
    num = num & ~(1 << k);
    printf("updated value after clearing the bit at positon %d is %d\n", k, num);
}
void toggle_bit(unsigned int num,int k)
{
    num = num ^ (1 << k);
    printf("updated value after toggling the bit at positon %d is %d\n",k, num);
}
void range_bits(unsigned int num, int m, int n)
{
    num = (num >> n);
    unsigned int mask = (1 << ((m-n)+1)) -1 ;
    num = num & mask;
    printf("Extrating bits from n: %d to m: %d and the value is %d\n",n, m, num);
}



int main(void)
{
    unsigned int num = 10;

    count(num);                
    rev(num);                 
    pow_2(num);               
    set_bit(num, 1);         
    clear_bit(num, 1);         
    toggle_bit(num, 2);      
    range_bits(num, 4, 1);    

    return 0;
}
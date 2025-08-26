#include <stdio.h>
#include <stdint.h>

int kernighan_algo(int n)
{
    int count = 0;
    while (n > 0)
    {
        n = n & (n - 1);    // Unsetting the LSB
        count += 1;         // increment count by 1 each time a set bit is unset 
    }
    return count;
}

unsigned int reverse_bits(unsigned int n)
{
    unsigned int temp = 1;
    unsigned int temp2;
    for (int i=0;i<32;i++)
    {
        temp = temp << i;
        temp2 = n & temp;
        if (temp2 != 0)
        {
            n = n & (~temp);
        }
        else
        {
            n = n | temp;
        }
    }
    return n;
}

void check_pow2(int num)
{
    int check = num & (num - 1);    // if a number is a power of 2 then only 1 bit is high.
    if (check)
    {
        printf("%d is not a power of 2\n",num);
    }
    else{
        printf("%d is a power of 2\n",num);
    }
}

int set_bit(int num,int position)
{
    int temp = 1 << position;
    num = num | temp;           // setting the specific bit by using bitwise or.
    return num;
}

int clear_bit(int num,int position)
{
    int temp = 1 << position;
    temp = ~temp;               // all 1's except for that position
    num = num & temp;           // clearing the specific bit by using bitwise and.
    return num;
}

int toggle_bit(int num,int position)
{
    int temp = 1 << position;
    int temp2 = temp & num;
    if (temp2 != 0)
    {
        temp = ~temp;
        num = num & temp;
    }
    else
    {
        num = num | temp; 
    }
    return num;
}

int main()
{
    int num = 5;
    //printf("%d\n",kernighan_algo(num));
    //printf("%u\n",reverse_bits((unsigned int)num));
    //printf("%u\n",UINT32_MAX);
    //check_pow2(num);
    //printf("%d\n",set_bit(num,1));
    //printf("%d\n",clear_bit(num,1));
    printf("%u\n",toggle_bit(num,2));
    return 0;
}
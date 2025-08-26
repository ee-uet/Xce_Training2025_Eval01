#include <stdio.h>

int one_count(int n){
    int count=0;
    while(n){
        n=n&(n-1);
        count++;
    }
    return count;
}
int revese_bits(int a){
    int temp=0;
    for (int i = 0; i < 32; i++)
    {
        temp=(temp <<1);
        temp=temp | (a & 1);
        a=(a>>1)& 0x7fffffff;
    }
    return temp;
}
void power_of_2(int n){
   if ((n & (n-1))==0){
    printf("number:%d is some power of 2\n",n);
   }else{
    printf("number:%d is not some power of 2\n",n);
   }
}

int set_bit(int a,int k){
    a=a|(1<<k);
    return a;
}

int clear_bit(int a,int k){
    a=a&(~(1<<k));
    return a;
}

int toggle_bit(int a,int k){
    int mask= a&(1<<k);
    if ((mask>>k)==0)
    {
        a=a|mask;
    }else
    {
        a=a&(~(mask));
    }
    return a;
}
int extract_range(int num,int m,int n){
    int mask=(0x7fffffff>>(30-m));
    num=mask&num;
    return (num>>n);
}

int main(){
    for (int i = 0; i < 10000000; i++)
    {
        printf("number of ones in %d are:%d\n",i,one_count(i));
        printf("The number before reversing:%x and after reversing:%x\n",i,revese_bits(i));
        power_of_2(i);
        printf("after setting K:%x bit of number:%x=%x\n",i%31,i,set_bit(i,i%32));
        printf("after clearing K:%x bit of number:%x=%x\n",i%31,~i,clear_bit(~i,i%32));
        printf("after toggling K:%x bit of number:%x=%x\n",i%32,~i,toggle_bit(~i,i%32));
        printf("number=>%x[%d:%d]=%x\n",~i,(i%16+i%16),i%32,extract_range(~i,(i%16+i%16),i%32));
    }
    
    return 0;
}
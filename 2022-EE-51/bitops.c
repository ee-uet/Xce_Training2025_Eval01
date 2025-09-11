#include <stdio.h>

int count_set_bits(int n){
    int count = 0;
    while (n > 0){
        count = count + (n & 1);
        n = n >> 1;
    }
    return count;
}

int reverse_bits(int n){
    int count = sizeof(n)*8 - 1;
    int reverse_num = n;
    
    n >>= 1;
    while (n > 0){
        reverse_num <<= 1;
        reverse_num |= n & 1;
        n >>= 1;
        count --;
    }
    reverse_num <<= count;
    return reverse_num;
}

void power_2(int n){
    if (n <= 0){
        printf("The number is not power of 2");
    }if ((n & (n - 1)) == 0){
        printf("The number is power of 2");
    }else{
        printf("The number is not power of 2");
    }
    return;
}

int set_bit(int n){
    int k;
    printf("Enter the bit to set : ");
    scanf("%d",&k);
    
    int m = 1 << k;
    int result = n | m;
    return result;
}

int clear_bit(int n){
    int k;
    printf("Enter the bit to clear : ");
    scanf("%d",&k);
    
    int m = 1 << k;
    int result = n &(~m);
    return result;
}

int toggle_bit(int n){
    int k;
    printf("Enter the bit to toggle : ");
    scanf("%d",&k);

    int m = 1 << k;
    int result = n ^ m;
    return result;
}
int extract_bits(int n){
    int m;
    int result;
    int start;
    printf("Enter the start bit : ");
    scanf("%d",&start);

    int end;
    printf("Enter the last bit : ");
    scanf("%d",&end);

    int size = start - end + 1;
    m = ((1 << size) - 1)<< end;
    result = (n & m) >> end;
    printf("The extracted bits are : %d\n",result);
    return result;
}

int main(void){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);
    printf("Number of set bits is %d\n",count_set_bits(n));
    printf("After reversing bits the number is %d\n",reverse_bits(n));
    power_2(n);
    printf("After setting the specific bit, the number is %d\n",set_bit(n));
    printf("After clearing the specific bit, the number is %d\n",clear_bit(n));
    printf("After toggling the specific bit, the number is %d\n",toggle_bit(n));
    extract_bits(n);

    return 0;
}
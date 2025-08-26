#include <stdio.h>
#include <stdint.h>
int main()
{       uint32_t reverse = 0;
	int count = 0;
	uint32_t a = 4;
	uint32_t temp = a;
	// no. of set bits
        while (a>0){
	      if (a & 1){
		      count++;
	      }
	      a=a>>1;
	}
printf("Number of set bits: %d\n", count);
printf("reversed string is: ");
// reversed string
for (int j=0; j<32; j++){
	reverse <<= 1;
	reverse |= (temp & 1);
	temp >>= 1;
}
for (int k = 31; k>=0; k--){
	printf("%u",((reverse>>k)&1));
       }
printf("\n");
// power of 2
a=4;
int powerof2=0;
if ((a!=0) && ((a & (a-1))==0))
{
	powerof2 = 1;
}

printf("Numbwr is power of 2: %d\n ",powerof2);
//--------------------set bit--------------------
uint32_t num;
uint32_t bit;
printf("Enter a number: \n");
scanf("%u",&num);

printf("Enter bit number to set \n");
scanf("%d",&bit);

uint32_t setbit = (num | (1 << bit));
printf("Bit %d Number %u is set 1: %u\n",bit, num, setbit); 
//-------------------------clear bit-----------------
uint32_t num2;
uint32_t bit2;
printf("Enter a number: \n");
scanf("%u",&num2);

printf("Enter bit number to clear \n");
scanf("%d",&bit2);

uint32_t clearbit = (num2 & (~(1 << bit2)));
printf("Bit %d Number %u is cleared: %u\n",bit2, num2, clearbit);
//------------------toggle bit------------
uint32_t num3;
uint32_t bit3;
printf("Enter a number: \n");
scanf("%u",&num3);

printf("Enter bit number to toggle \n");
scanf("%d",&bit3);

uint32_t togglebit = (num3 ^ (1 << bit3));
printf("Bit %d Number %u is toggled: %u\n",bit3, num3, togglebit);

//------------------range of bits------------------
uint32_t num4;
uint32_t sbit;
uint32_t ebit;
uint32_t extractedBits;
printf("Enter a number: \n");
scanf("%u",&num4);

printf("Enter starting bit \n");
scanf("%d",&sbit);

printf("Enter ending bit \n");
scanf("%d",&ebit);
printf("bits between %d and %d of %u are: ",sbit,ebit,num4);
uint32_t mask = (1 << (sbit - ebit+1))-1;
extractedBits = (num4>>ebit) & mask;
printf("Extracted Bits are: ");
for (int m = sbit-ebit; m>=0; m--){
	printf("%u", (extractedBits >> m)&1);
}
printf("\n");
return 0;
}







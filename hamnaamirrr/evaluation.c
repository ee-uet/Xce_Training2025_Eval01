#include <stdio.h>
int countset(int num){
   
    int count;
    while(num > 0){
        count = count + (num & 1);
        num = num >> 1;
    }
    return count;
}
int main(){
    int n;
     n = 5;
    // printf("the count is %d\n",countset(n));
    // printf("print the number is %d\n",reversebits(n));
     //powerof2( n);
    // setbit();
    // clearbit();
    //toggle();
     extractbits();
     
     return 0;

}
int reversebits(int num){
     int count=0;
     int i;
     int r_num;
     while (num > 0){
       r_num = num << 1 ;
       r_num =r_num | (num & 1);
       num = num >> 1;
} 
    return (r_num);

}    

int powerof2(int num){
  if ((num & (num-1)) == 0){ // added parentheses
   printf("%d is a power of 2\n",num);
  }
  else{ 
    printf("it is not a power of 2\n",num);
  }
}
int setbit(){
    int number;
    int pos;
    int bit;
    printf("input number");
    scanf("%d",&number);
    printf("input position");
    scanf("%d",&pos); 
    bit = 1 << pos;
   
    number = number | bit;
    
    printf("%d",number);
    }

    
int clearbit (){
    int number;
    int pos;
    int bit;
    printf("input number");
    scanf("%d",&number);
     printf("input position");
    scanf("%d",&pos) ; 
    
    bit = 1 << pos;
    bit = ~bit;
    number = number & bit;
    
    printf("%d",number);

}

int toggle(){
    int pos;
    int bit;
    int num;
    int n;
    printf("enter specific position");
    scanf("%d",&pos);
    scanf("%d",&num);
    bit = 1 << pos;
     n= bit ^ num;
     printf ("%d",n);
}

int extractbits(){
    int start;
    int end;
    int num;
    int bit = 0;
    int i;
    printf("input starting index keeping ur no in mind");
    scanf("%d",&start);
    printf("input ending index");
    scanf("%d",&end);
    printf("input number");
    scanf("%d",&num);
   for (i = start; i<= end; i++ ){
     bit = bit | (1 << i);

   }
   printf("%d",bit & num);


}
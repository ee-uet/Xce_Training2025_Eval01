#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int counter(int num){
  int count = 0;
  while(num != 0){
    num = num & (num - 1);
    count++;
  }
  return count;
}

void reverse(int* ptr){

  int deref = *ptr; *ptr = 0;
  
  for (int i = 0; i < 32; i++){
    *ptr |= deref & (1U << 31 - i); 
  }
}

int powtwo(int* ptr){
  *ptr = *ptr < 0 ? ~(*ptr) + 1 : *ptr;  
  return ((*ptr & 0x1) == 0) && (*ptr != 0);
}

void setbit(int* ptr, int n){
  *ptr = *ptr | (1U << n);
}

void clearbit(int* ptr, int n){
  *ptr = *ptr & ~(1U << n);
}

void togglebit(int* ptr, int n){
  *ptr = *ptr ^ (1U << n);
}

int extractbits(int* ptr, int m, int n){
  
  int mask = 0;
  
  while (m >= n){
    mask = mask | ((1U << m) | (1U << n));
    m--; n++;
  }
  
  return *ptr & mask;
}

int main(int argc, char* argv[]){

  if (argc < 3){
    return -1;
  }

  int test = atoi(argv[1]);
  int num = atoi(argv[2]);

  int m = atoi(argv[3]);
  int n = atoi(argv[4]);

  int result = 0;

  switch(test){
    case 1:
            result = counter(num);
            printf("%d\n", result); 
            return 0;
    case 2: 
            reverse(&num);
            printf("%d\n", num);
            return 0;
    case 3: 
            result = powtwo(&num);
            printf("%d\n", result);
            return 0;
    case 4:
            setbit(&num, m);
            printf("%d\n", num);
            return 0;
    case 5:
            clearbit(&num, m);
            printf("%d\n", num);
            return 0;
    case 6: 
            togglebit(&num, m);
            printf("%d\n", num);
            return 0;
    case 7: 
            result = extractbits(&num, m, n);
            printf("%d\n", result);
            return 0;
  }

  return -1;
}



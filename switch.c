#include <stdio.h>

int main(){

int a ;
int b ;
int c;

int num ;
printf(" Enter first number ");
scanf(" %d" , &a);
printf(" Enter second number ");
scanf("%d" , &b);

printf("enter number 1 to 5");
scanf("%d" , &num);

switch(num){
  case 1 : c = a + b;
  printf(" Addition %d" , c);
  break;
  
  case 2 : c = a - b;
  printf(" Subtraction %d" , c);
  break;
  
  case 3 : c = a/b;
  printf(" Division %d" , c);
  break;
  
  case 4 : c = a%b;
  printf(" Modulus %d" , c);
  break;
  
  case 5 : c = a*b;
  printf(" Multiplication %d" , c);
  break;
  
  default : printf(" Invalid ");
  
  }
  
  return 0;
  
  
  
}

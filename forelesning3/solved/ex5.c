// ex5.c: Lession 3, exercise 4:
//
// cl /Od /Zi ex5.c
// gcc -O2 ex5.c -o ex5
//
// -or- make TARGET=ex5
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FALSE 0
#define TRUE (!0)

int IsPrime (unsigned int iNum);

void main (void)
{
   int a;

   srand(time(NULL));
   a = rand() % 20;

/*
   if (a == 1){
      printf("%d is 1", a);
   }
   else if(a%2 == 0){
      printf("%d is not a prime", a);
   }
   else if(a%3 == 0){
      printf("%d is not a prime", a);
   }
   else if(a%5 == 0){
      printf("%d is not a prime", a);
   }
   else if(a%7 == 0){
      printf("%d is not a prime", a);
   }
   else if(a%11 == 0){
      printf("%d is not a prime", a);
   }
   else if(a%13 == 0){
      printf("%d is not a prime", a);
   }
   else if(a%17 == 0){
      printf("%d is not a prime", a);
   }
   else if(a%19 == 0){
      printf("%d is not a prime", a);
   }
   else{
      printf("%d is a prime", a);
   }
*/
   // Using if or switch for this is just dumb...
   if (IsPrime(a)) {
      printf("%d is a prime.\n", a);
   }
   else {
      printf("%d is not a prime.\n", a);
   }
}

int IsPrime (unsigned int iNum)
{
   int i;
   if (iNum < 2) return FALSE;
   for (i = 2; i < iNum; i++) {
      if ((iNum % i) == 0) return FALSE;
   }
   return TRUE;
}


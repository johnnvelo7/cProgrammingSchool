// ex1.c: Lession 3, exercise 6:
//
// cl /Od /Zi ex6.c
// gcc -O2 ex6.c -o ex6
//
// -or- make TARGET=ex6
//

#include <stdio.h>

int Fibonacci (int n);

int main (int iArgC, char *apszArgV[])
{
   int iNum;

   if (iArgC < 2) {
      printf ("Usage: ex6 <number>\n");
      return 1;
   }
   iNum = atoi(apszArgV[1]);

   if (iNum == 0) {
      printf ("Please enter a non-zero argument.\n");
      return 1;
   }

   printf ("Fibonacci number a[%d] = %d.\n", iNum, Fibonacci(iNum));

}

// Fibonacci series:
// a[n] = a[n-1] + a[n-2]
// a[0] = 0
// a[1] = 1

int Fibonacci (int n)
{
   if (n == 0) {
      return 0;
   }
   if (n == 1) {
      return 1;
   }
   return Fibonacci(n-1) + Fibonacci(n-2);
}



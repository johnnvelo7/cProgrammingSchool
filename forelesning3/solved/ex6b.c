// ex1.c: Lession 3, exercise 6a:
//
// cl /Od /Zi ex6a.c
// gcc -O2 ex6a.c -o ex6a
//
// -or- make TARGET=ex6a
//

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

int Fibonacci (int n);
int QuickFibonacchi (int n);
unsigned long GetTime (void);
unsigned long lIterations = 0;

int main (int iArgC, char *apszArgV[])
{
   int iNum;
   unsigned long lTimeStart, lTimeEnd;

   if (iArgC < 2) {
      printf ("Usage: ex6 <number>\n");
      return 1;
   }
   iNum = atoi(apszArgV[1]);

   if (iNum == 0) {
      printf ("Please enter a non-zero argument.\n");
      return 1;
   }
   lTimeStart = GetTime();
   printf ("Fibonacci number a[%d] = %d.\n", iNum, Fibonacci(iNum));
   lTimeEnd = GetTime();
   printf ("Calculated in %lu ms. %lu iterations.\n", lTimeEnd - lTimeStart, lIterations);

   lTimeStart = GetTime();
   printf ("Quick Fibonacci number a[%d] = %d.\n", iNum, QuickFibonacchi(iNum));
   lTimeEnd = GetTime();
   printf ("Calculated in %lu ms.\n", lTimeEnd - lTimeStart);

}

// Fibonacci series:
// a[n] = a[n-1] + a[n-2]
// a[0] = 0
// a[1] = 1

int Fibonacci (int n)
{
   ++lIterations;
   if (n == 0) {
      return 0;
   }
   if (n == 1) {
      return 1;
   }
   return Fibonacci(n-1) + Fibonacci(n-2);
}

int QuickFibonacchi (int n)
{
   int an1 = 1, an2 = 1, an, i;
   if (n == 0) {
      return 0;
   }
   for (i = 3; i <= n; i++) {
      an = an1 + an2;
      an1 = an2;
      an2 = an;
   }
   return an;
}

#ifdef _WIN32
unsigned long GetTime (void)
{
   return GetTickCount();
}
#else
unsigned long GetTime (void)
{
   struct timeval tv;
   gettimeofday(&tv,NULL);
   return (tv.tv_sec * 1000L) + (tv.tv_usec / 1000L);
}
#endif

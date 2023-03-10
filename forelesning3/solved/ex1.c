// ex1.c: Lession 3, exercise 1:
//
// cl /Od /Zi ex1.c
// gcc -O2 ex1.c -o ex1
//
// -or- make TARGET=ex1
//

#include <stdio.h>

void main (void)
{
   char c;
   int i;
   long li;
   float f;
   double df;

   char *pc;
   int *pi;
   long *pl;
   float *pf;
   double *pd;
   void *pv;

   int ia[20];

   printf ("Size of char is %d.\n", (int)sizeof(c));
   printf ("Size of int is %d.\n", (int) sizeof(i));
   printf ("Size of long is %d.\n", (int) sizeof(li));
   printf ("Size of float is %d.\n", (int) sizeof(f));
   printf ("Size of double is %d.\n\n", (int) sizeof(df));

   printf ("Size of char* is %d.\n", (int) sizeof(pc));
   printf ("Size of int* is %d.\n", (int) sizeof(pi));
   printf ("Size of long* is %d.\n", (int) sizeof(pl));
   printf ("Size of float* is %d.\n", (int) sizeof(pf));
   printf ("Size of double* is %d.\n\n", (int) sizeof(pd));

   printf ("Size of void* is %d.\n", (int) sizeof(pv));

   printf ("Size of int array [20] is %d.\n", (int) sizeof(ia));

}

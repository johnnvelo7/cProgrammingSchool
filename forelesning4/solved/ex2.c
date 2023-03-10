// ex1.c: Lession 4, exercise 2:
//
// cl /Od /Zi ex2.c
// gcc -O2 ex2.c -o ex2
//
// -or- make TARGET=ex2
//

#include <stdio.h>

void main (void)
{
   int *pInt;
   char *pChar;
   short *pShort;
   double *pDouble;

   printf("The size of pointers are %lu, %lu, %lu, %lu respectively \n",
   sizeof(pInt), sizeof(pChar), sizeof(pShort), sizeof(pDouble));

   printf("The size of variables are %lu, %lu, %lu, %lu respectively \n",
   sizeof(*pInt), sizeof(*pChar), sizeof(*pShort), sizeof(*pDouble));
}

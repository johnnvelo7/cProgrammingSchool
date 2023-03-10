// ex3.c: Lession 3, exercise 3:
//
// cl /Od /Zi ex3.c
// gcc -O2 ex3.c -o ex3
//
// -or- make TARGET=ex3
//

#include <stdio.h>
#include <stdlib.h>

int main (int iArgC, char *apszArgV[])
{
   int iNum = 0;

   if (iArgC < 2) {
      printf ("Usage: ex3 <number>\n");
      return 1;
   }
   iNum = atoi(apszArgV[1]);
   if (iNum == 0) {
      printf ("Please enter a non-zero argument.\n");
      return 1;
   }

   if ((iNum % 2) == 0) {
      printf ("Number %d is read and it is even.\n", iNum);
   }
   else {
      printf ("Number %d is read and it is odd.\n", iNum);
   }

   // printf ("Number %d is read and it is %s.\n", ((iNum % 2) == 0)? "even":"odd");

   return 0;
}

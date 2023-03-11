// ex3.c: Lession 4, exercise 6 (Obligatory exercise):
//
// cl /Od /Zi ex6.c
// gcc -O2 ex6.c -o ex6
//
// -or- make TARGET=ex6
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BubbleSort (char *apszArray[], int iSze);
void PrintArray (char *apszArray[], int iSze);
void Swap (char **ppszA, char **psszB);

int main (int iArgC, char *apszArgV[])
{
   if (iArgC < 2) {
      printf ("Usage: ex6 <string1> <string2> ... <stringN>\n");
      return 1;
   }

   BubbleSort (&apszArgV[1], iArgC - 1); // Sort the array
   PrintArray (&apszArgV[1], iArgC - 1); // And print it.

   return 0;
}

// Use preprocessor defines to make more readable constants:

#define FALSE 0
#define TRUE  1

// Run through the elements and swap when you find a[i-1] > a[i].
// Keep doing this until you cannot swap anymore.

void BubbleSort (char *apszArray[], int iSze)
{
   int bHasSwapped = TRUE;
   while (bHasSwapped) {
      bHasSwapped = FALSE;
      for (int i = 1; i < iSze; i++) {
         if (strcmp(apszArray[i-1], apszArray[i]) > 0) {
            Swap (&apszArray[i-1], &apszArray[i]);
            bHasSwapped = TRUE;
            // PrintArray (apszArray, iSze);
         }
      }
   }
}

void Swap (char **ppA, char **ppB)
{
   char *pTmp;
   pTmp = *ppA;
   *ppA = *ppB;
   *ppB = pTmp;
}

void PrintArray (char *apszArray[], int iSze)
{
   printf ("Number of strings %d: \n", iSze);
   for (int i = 0; i < iSze; i++) {
      printf ("%d: %s\n", i, apszArray[i]);
   }
}


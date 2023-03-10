// ex3.c: Lession 4, exercise 4:
//
// cl /Od /Zi ex4.c
// gcc -O2 ex4.c -o ex4
//
// -or- make TARGET=ex4
//

#include <stdio.h>
#include <stdlib.h>

void BubbleSort (int aiArray[], int iSze);
void Swap (int *pi, int *pj);
void PrintArray (int aiArray[], int iSze);

int main (int iArgC, char *apszArgV[])
{
   int *aiNumbers = NULL;
   int iCount = iArgC - 1;

   if (iArgC < 2) {
      printf ("Usage: ex4 <number1> <number2> ... <numberN>\n");
      return 1;
   }

   // Allocate memory and test if Ok:
   aiNumbers = (int *) malloc (iCount * sizeof(int));
   if (aiNumbers == NULL) return 1;

   // Obtain numbers from command line:
   for (int i = 0; i < iCount; i++) {
      aiNumbers[i] = atoi(apszArgV[i + 1]);
   }

   // Sort the numbers:
   BubbleSort (aiNumbers, iCount);

   // Print the numbers:
   PrintArray (aiNumbers, iCount);

   free (aiNumbers);

   return 0;
}

// Use preprocessor defines to make more readable constants:

#define FALSE 0
#define TRUE  1

// Run through the elements and swap when you find a[i-1] > a[i].
// Keep doing this until you cannot swap anymore.

void BubbleSort (int aiArray[], int iSze)
{
   int bHasSwapped = TRUE;
   while (bHasSwapped) {
      bHasSwapped = FALSE;
      for (int i = 1; i < iSze; i++) {
         if (aiArray[i-1] > aiArray[i]) {
            Swap (&aiArray[i-1], &aiArray[i]);
            bHasSwapped = TRUE;
            // PrintArray (aiArray, iSze);
         }
      }
   }
}

void Swap (int *pi, int *pj)
{
   int iTmp = *pi;
   *pi = *pj;
   *pj = iTmp;
}

void PrintArray (int aiArray[], int iSze)
{
   printf ("%d: ", iSze);
   for (int i = 0; i < iSze; i++) {
      printf ("%d ", aiArray[i]);
   }
   printf ("\n");
}


// ex3.c: Lession 7, exercise 3
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

static void PrintList (LIST *pHead);

int main (void)
{
   LIST *pHead = NULL;
   LIST *pThis = NULL;
   int iRc = OK;

   char *apszStrings[] = {"String number 1", "Second string", "Third string", "String number 4", NULL};
   char *pszFifth = "The 5th Element";

   for (int i = 0; apszStrings[i]; i++) {
      iRc = InsertInList (&pHead, apszStrings[i], strlen(apszStrings[i])+1);
      if (iRc != OK) break;
   }

   if (iRc != OK) {
      printf ("Something went wrong.\n");
      return 1;
   }

   PrintList (pHead);
   iRc = AddToList (&pHead, pszFifth, strlen(pszFifth) + 1);

   if (iRc != OK) {
      printf ("Something went wrong.\n");
      return 1;
   }

   PrintList (pHead);

   // Pick out the 3rd element in the list:
   pThis = pHead;
   for (int i = 0; pThis != NULL && i < 2; i++) {
      pThis = pThis->pNext;
   }

   // And remove it:
   if (pThis != NULL) {
      iRc = RemoveFromList (&pHead, pThis);
   }

   if (iRc != OK) {
      printf ("Something went wrong.\n");
      return 1;
   }

   PrintList (pHead);

   // Remove first element in list
   iRc = RemoveFromList (&pHead, pHead);
   if (iRc == OK) {
      PrintList (pHead);
   }

}

static void PrintList (LIST *pThis)
{
   int i = 0;
   while (pThis) {
      printf ("%d: %s\n", ++i, pThis->cBuf);
      pThis = pThis->pNext;
   }
   printf ("\n");
}


// ex3.c: Lession 7, exercise 3
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "doublylinkedlist.h"

static void PrintList (LIST *pHead);

int main (void)
{
   LISTHEAD sListHead = {NULL, NULL};
   int iRc = OK;

   char *apszStrings[] = {"String number 1", "Second string", "Third string", "String number 4", NULL};
   char *pszFifth = "The 5th Element";

   for (int i = 0; apszStrings[i]; i++) {
      iRc = InsertInList (&sListHead, apszStrings[i], strlen(apszStrings[i])+1);
      if (iRc != OK) break;
   }

   if (iRc != OK) {
      printf ("Something went wrong.\n");
      return 1;
   }

   PrintList (sListHead.pHead);
   iRc = AddToList (&sListHead, pszFifth, strlen(pszFifth) + 1);

   if (iRc != OK) {
      printf ("Something went wrong.\n");
      return 1;
   }

   PrintList (sListHead.pHead);

   // Pick out the 3rd element in the list:
   LIST *pThis = sListHead.pHead;
   for (int i = 0; pThis != NULL && i < 2; i++) {
      pThis = pThis->pNext;
   }

   // And remove it:
   if (pThis != NULL) {
      iRc = RemoveFromList (&sListHead, pThis);
   }

   if (iRc != OK) {
      printf ("Something went wrong.\n");
      return 1;
   }

   PrintList (sListHead.pHead);

   // Remove first element in list
   iRc = RemoveFromList (&sListHead, sListHead.pHead);
   if (iRc == OK) {
      PrintList (sListHead.pHead);
   }

   // Remove last element in list
   iRc = RemoveFromList (&sListHead, sListHead.pTail);
   if (iRc == OK) {
      PrintList (sListHead.pHead);
   }

}

static void PrintList (LIST *pThis)
{
   int i = 0;
   while (pThis) {
      printf ("%d: %s\n", ++i, pThis->byBuf);
      pThis = pThis->pNext;
   }
   printf ("\n");
}


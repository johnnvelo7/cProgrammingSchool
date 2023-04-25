// ex3.c: Lession 7, exercise 3
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

static void PrintList (char *pszLabel, LIST *pThis);

int main (void)
{
   LIST *pHead = NULL;
   LIST *pThis = NULL;
   int iRc = OK;

   char *apszStrings[] = {"String number 1", "Second string", "Third string", "String number 4", NULL};
   char *pszFifth = "The 5th Element";

   for (int i = 0; apszStrings[i]; i++) {
      iRc = InsertInList (&pHead, apszStrings[i]);
      if (iRc != OK) break;
   }

   if (iRc != OK) {
      printf ("Something went wrong.\n");
      return 1;
   }

   PrintList ("Inserted 4 elements", pHead);
   iRc = AddToList (&pHead, pszFifth);

   if (iRc != OK) {
      printf ("Something went wrong.\n");
      return 1;
   }

   PrintList ("Added element", pHead);

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

   PrintList ("Removed 3rd element", pHead);

   // Remove first element in list
   iRc = RemoveFromList (&pHead, pHead);
   if (iRc == OK) {
      PrintList ("Removed first element", pHead);
   }

   char *pszSixth = "The 6th Element (not a movie)";
   char *psz7th = "Argc argv!!";

   iRc = AddToList (&pHead, pszSixth);
   iRc = AddToList (&pHead, psz7th);
   if (iRc == OK) {
      PrintList ("Before sort", pHead);
   }

   iRc = SortList (&pHead);
   if (iRc == OK) {
      PrintList ("After sort", pHead);
   }

   char *psz8th = "Bullocks!";
   iRc = AddToListSorted (&pHead, psz8th);
   if (iRc == OK) {
      PrintList ("After inserted string sorted", pHead);
   }

   char *psz9th = "And another one";
   iRc = AddToListSorted (&pHead, psz9th);
   if (iRc == OK) {
      PrintList ("After inserted string sorted", pHead);
   }

   char *psz10th = "Third one!";
   iRc = AddToListSorted (&pHead, psz10th);
   if (iRc == OK) {
      PrintList ("After inserted string sorted", pHead);
   }

   char *psz11th = "Zapp!";
   iRc = AddToListSorted (&pHead, psz11th);
   if (iRc == OK) {
      PrintList ("After inserted string sorted", pHead);
   }

}

static void PrintList (char *pszLabel, LIST *pThis)
{
   int i = 0;
   if (pszLabel) printf ("%s:\n", pszLabel);
   while (pThis) {
      printf ("%d: %s\n", ++i, pThis->szString);
      pThis = pThis->pNext;
   }
   printf ("\n");
}


// list.c: Lession 9, exercise 2
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

static LIST *CreateNode (const char *pszKey, const char *pszValue, const int iValue)
{
   LIST *pThis = malloc (sizeof(LIST));
   if (pThis != NULL) {
      memset (pThis, 0, sizeof(LIST));
      strncpy (pThis->szKey, pszKey, MAX_KEY - 1);
      if (pszValue) {
         pThis->pszValue = malloc (strlen(pszValue) + 1);
         if (pThis->pszValue) {
            strcpy (pThis->pszValue, pszValue);
         }
         else {
            free (pThis);
            pThis = NULL;
         }
      }
      else {
         pThis->iValue = iValue;
      }
   }
   return pThis;
}

static int _RemoveFromList (LIST **ppHead, LIST *pToDelete)
{
   int iRc = ERROR;
   LIST *pThis = NULL;
   LIST *pPrev = NULL;

   if (*ppHead == pToDelete) {
      *ppHead = pToDelete->pNext;
      iRc = OK;
   }
   else {
      pThis = *ppHead;
      while (pThis != NULL) {
         if (pThis == pToDelete) {
            pPrev->pNext = pThis->pNext;
            iRc = OK;
            break;
         }
         pPrev = pThis;
         pThis = pThis->pNext;
      }
   }
   return iRc;
}

// This one goes beyond the assignment...

int SortList (LIST **ppHead)
{
   LIST *pThis, **ppNewHead;
   int iRc = ERROR;

   for (ppNewHead = ppHead; *ppNewHead; ppNewHead = &((*ppNewHead)->pNext)) {
      for (pThis = (*ppNewHead)->pNext; pThis; pThis = pThis->pNext) {
         // Find out if the this node is below the head alphabetically:
         if (strcmp(pThis->szKey, (*ppNewHead)->szKey) < 0) {
            // If so, remove this node from the list (but don't destroy it)
            if ((iRc = _RemoveFromList (ppNewHead, pThis)) == OK) {
               // .. and insert it as new head.
               pThis->pNext = *ppNewHead;
               *ppNewHead = pThis;
            }
         }
         if (iRc != OK) break;
      }
      if (iRc != OK) break;
   }
   return iRc;
}

int InsertSorted (LIST **ppHead, const char *pszKey, const char *pszValue, const int iValue)
{
   int iRc = ERROR;
   LIST *pPrev = NULL;
   LIST *pThis = NULL;
   LIST *pNew = CreateNode (pszKey, pszValue, iValue);

   // Empty list?
   if (*ppHead == NULL) {
      // if so, insert as new head.
      *ppHead = pNew;
      iRc = OK;
   }

   // Test first if the new node is below the head alphabetically:
   else if (strcmp(pNew->szKey, (*ppHead)->szKey) < 0) {
      // if so, insert as new head.
      pNew->pNext = *ppHead;
      *ppHead = pNew;
      iRc = OK;
   }

   // Otherwise look for where to insert it ...
   else {
      pPrev = *ppHead;
      pThis = (*ppHead)->pNext;

      // Test for only one node in the list.
      if (pThis == NULL) {
         // If so, we should be number two:
         pPrev->pNext = pNew;
         iRc = OK;
      }
      else {
         while (pThis != NULL) {
            if (strcmp(pNew->szKey, pThis->szKey) < 0) {
               // We have found our place in between pPrev and pThis:
               pNew->pNext = pPrev->pNext;
               pPrev->pNext = pNew;
               iRc = OK;
               break;
            }
            pPrev = pThis;
            pThis = pThis->pNext;
         }
         // We didn't find our place. Add at end:
         if (pThis == NULL) {
            pPrev->pNext = pNew;
            iRc = OK;
         }
      }
   }
   return iRc;
}

int Lookup (LIST *pHead, const char *pszKey, char **ppszValue, int *piValue)
{
   int iRc = ERROR;
   LIST *pThis;

   for (pThis = pHead; pThis; pThis = pThis->pNext) {
      if (strcmp(pThis->szKey, pszKey) == 0) {
         *ppszValue = pThis->pszValue;
         *piValue = pThis->iValue;
         iRc = OK;
         break;
      }
   }
   return iRc;
}

int Delete (LIST **ppHead, const char *pszKey)
{
   int iRc = ERROR;
   LIST *pThis;

   for (pThis = *ppHead; pThis; pThis = pThis->pNext) {
      if (strcmp(pThis->szKey, pszKey) == 0) {
         iRc = _RemoveFromList (ppHead, pThis);
         free (pThis);
         break;
      }
   }
   return iRc;
}

int Dumplist (LIST *pHead)
{
   int iRc = ERROR;
   LIST *pThis;

   printf ("\nThe list:\n");
   for (pThis = pHead; pThis; pThis = pThis->pNext) {
      if (pThis->pszValue) {
         printf ("%s = '%s'.\n", pThis->szKey, pThis->pszValue);
      }
      else {
         printf ("%s = %d.\n", pThis->szKey, pThis->iValue);
      }
   }
   return iRc;
}


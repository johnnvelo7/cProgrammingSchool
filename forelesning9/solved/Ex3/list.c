// list.c: Lession 9, exercise 2
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

static LIST *CreateNode (char *pszString)
{
   int iSze = strlen(pszString) + 1;
   LIST *pThis = malloc (sizeof(LIST) + iSze);
   if (pThis != NULL) {
      memset (pThis, 0, sizeof(LIST) + iSze);
      strcpy (pThis->szString, pszString);
   }
   return pThis;
}


int InsertInList (LIST **ppHead, char *pszString)
{
   int iRc = ERROR;
   LIST *pThis = CreateNode (pszString);
   if (pThis != NULL) {
      pThis->pNext = *ppHead;
      *ppHead = pThis;
      iRc = OK;
   }
   return iRc;
}

int AddToList (LIST **ppHead, char *pszString)
{
   int iRc = ERROR;
   LIST *pThis = CreateNode (pszString);
   if (pThis != NULL) {
      if (*ppHead == NULL) {
         *ppHead = pThis;
         iRc = OK;
      }
      else {
         LIST *pList = *ppHead;
         while (pList->pNext != NULL) {
            pList = pList->pNext;
         }
         pList->pNext = pThis;
         iRc = OK;
      }
   }
   return iRc;
}

static int _RemoveFromList (LIST **ppHead, LIST *pToDelete, int iDestroyNode)
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
   if ((iRc == OK) && iDestroyNode) free (pToDelete);
   return iRc;
}

int RemoveFromList (LIST **ppHead, LIST *pToDelete)
{
   return _RemoveFromList (ppHead, pToDelete, TRUE);
}

// This one is tough...

int SortList (LIST **ppHead)
{
   LIST *pThis, **ppNewHead;
   int iRc = ERROR;

   for (ppNewHead = ppHead; *ppNewHead; ppNewHead = &((*ppNewHead)->pNext)) {
      for (pThis = (*ppNewHead)->pNext; pThis; pThis = pThis->pNext) {
         // Find out if the this node is below the head alphabetically:
         if (strcmp(pThis->szString, (*ppNewHead)->szString) < 0) {
            // If so, remove this node from the list (but don't destroy it)
            if ((iRc = _RemoveFromList (ppNewHead, pThis, FALSE)) == OK) {
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

// This is MUCH simpler! (Eh, well...)

int AddToListSorted (LIST **ppHead, char *pszString)
{
   int iRc = ERROR;
   LIST *pPrev = NULL;
   LIST *pThis = NULL;
   LIST *pNew = CreateNode (pszString);

   // Empty list?
   if (*ppHead == NULL) {
      // if so, insert as new head.
      *ppHead = pNew;
      iRc = OK;
   }

   // Test first if the new node is below the head alphabetically:
   else if (strcmp(pNew->szString, (*ppHead)->szString) < 0) {
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
            if (strcmp(pNew->szString, pThis->szString) < 0) {
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


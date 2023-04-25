//
// list.c: Lession 9, exercise 1 (Lession 9 / Example
// rewritten as double linked list.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "doublylinkedlist.h"

static LIST *CreateNode (void *pvData, int iSze)
{
   LIST *pThis = malloc (sizeof(LIST) + iSze);
   if (pThis != NULL) {
      memset (pThis, 0, sizeof(LIST) + iSze);
      pThis->iSze = iSze;
      memcpy (pThis->byBuf, pvData, iSze);
   }
   return pThis;
}


int InsertInList (LISTHEAD *pListHead, void *pvData, int iSze)
{
   int iRc = ERROR;
   LIST *pThis = CreateNode (pvData, iSze);
   if (pThis != NULL) {
      // Test for empty list:
      if (pListHead->pHead == NULL) {
         pListHead->pHead = pThis;         // I'm the only one, both head and tail.
         pListHead->pTail = pThis;
      }
      else {
         // Insert in beginning of list:
         pListHead->pHead->pPrev = pThis;  // The former first should point back at me.
         pThis->pNext = pListHead->pHead;  // I should point at the former first.
         pListHead->pHead = pThis;         // The list head should point at me.
      }
      iRc = OK;                         // Thats it! We don't do anything with the tail.
   }
   return iRc;
}

int AddToList (LISTHEAD *pListHead, void *pvData, int iSze)
{
   int iRc = ERROR;
   LIST *pThis = CreateNode (pvData, iSze);
   if (pThis != NULL) {
      // Test for empty list:
      if (pListHead->pHead == NULL) {
         pListHead->pHead = pThis;         // I'm the only one, both head and tail.
         pListHead->pTail = pThis;
      }
      else {
         // Insert in the end of the list:
         pListHead->pTail->pNext = pThis;  // The former last should point fwd at me.
         pThis->pPrev = pListHead->pTail;  // I should point back at the former last.
         pListHead->pTail = pThis;         // The list tail should point at me.
      }
      iRc = OK;                         // Thats it! We don't do anything with the head.
   }
   return iRc;
}

int RemoveFromList (LISTHEAD *pListHead, LIST *pToDelete)
{
   int iRc = ERROR;
   LIST *pThis = NULL;
   LIST *pPrev = NULL;

   // Test first for empty list:
   if (pListHead->pHead != NULL) {
      // Are we deleting the first (head) element?
      if (pListHead->pHead == pToDelete) {
         pListHead->pHead = pToDelete->pNext;
         pListHead->pHead->pPrev = NULL;
         iRc = OK;
      }
      // or are we deleting the last (tail) element?
      else if (pListHead->pTail == pToDelete) {
         pListHead->pTail = pToDelete->pPrev;
         pListHead->pTail->pNext = NULL;
         iRc = OK;
      }
      // or are we deleting some other element?
      else {
         pThis = pListHead->pHead;
         while (pThis != NULL) {
            if (pThis == pToDelete) {
               pPrev->pNext = pThis->pNext;
               pThis->pNext->pPrev = pThis->pPrev;
               iRc = OK;
               break;
            }
            pPrev = pThis;
            pThis = pThis->pNext;
         }
      }
      if (iRc == OK) free (pToDelete);
   }
   return iRc;
}

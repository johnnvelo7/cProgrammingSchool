// list.h: Lession 7, exercise 3
//
//
#ifndef _LIST_H_
#define _LIST_H_

#define OK      0
#define ERROR   1

// The list type:

typedef unsigned char BYTE;

typedef struct _LIST {
   struct _LIST *pNext;
   struct _LIST *pPrev;
   int iSze;
   BYTE byBuf[];
} LIST;

// The list head type:

typedef struct _LISTHEAD {
   LIST *pHead;
   LIST *pTail;
} LISTHEAD;

// Prototypes - functions return OK or ERROR.

int InsertInList (LISTHEAD *pHead, void *pvData, int iSze);
int AddToList (LISTHEAD *pHead, void *pvData, int iSze);
int RemoveFromList (LISTHEAD *pHead, LIST *pToDelete);

#endif // ndef _LIST_H

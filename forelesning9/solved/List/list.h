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
   int iSze;
   BYTE byBuf[];
} LIST;

// Prototypes - functions return OK or ERROR.

int InsertInList (LIST **ppHead, void *pvData, int iSze);
int AddToList (LIST **ppHead, void *pvData, int iSze);
int RemoveFromList (LIST **ppHead, LIST *pToDelete);

#endif // ndef _LIST_H

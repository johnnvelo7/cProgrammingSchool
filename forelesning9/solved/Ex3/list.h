// list.h: Lession 9, exercise 2
//
//
#ifndef _LIST_H_
#define _LIST_H_

#define OK      0
#define ERROR   1

#define FALSE   0
#define TRUE    1

// The list type:

typedef struct _LIST {
   struct _LIST *pNext;
   char szString[];
} LIST;

// Prototypes - functions return OK or ERROR.

int InsertInList (LIST **ppHead, char *pszString);
int AddToList (LIST **ppHead, char *pszString);
int RemoveFromList (LIST **ppHead, LIST *pToDelete);

int AddToListSorted (LIST **ppHead, char *pszString);
int SortList (LIST **ppHead);

#endif // ndef _LIST_H

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

#define MAX_KEY 32

typedef struct _LIST {
   struct _LIST *pNext;
   char szKey[MAX_KEY];
   char *pszValue;
   int  iValue;
} LIST;

// Prototypes - functions return OK or ERROR.

int InsertSorted (LIST **ppHead, const char *pszKey, const char *pszValue, const int iValue);
int Lookup (LIST *pHead, const char *pszKey, char **ppszValue, int *piValue);
int Delete (LIST **ppHead, const char *pszKey);
int Dumplist (LIST *pHead);

#endif // ndef _LIST_H

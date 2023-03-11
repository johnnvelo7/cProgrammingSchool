// ex2.c: Lession 5 - exercise 2
//
// Windows: cl /Od /Zi ex2.c
// Linux: gcc -O2 ex2.c -o ex2
//
// -or- make TARGET=ex2
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int MyStrLen (char *pc)
{
  int iLen = 0;
  if (pc != NULL) {
    while (*pc++) ++iLen;
    // while (*pc++ != '\0') ++iLen;
  }
  return iLen;
}

void main (void)
{
  char szStr[] = "Hello on the bathroom";

  printf ("%s = %d\n", szStr, (int)strlen(szStr));
  printf ("%s = %d\n", szStr, (int)MyStrLen(szStr));
}


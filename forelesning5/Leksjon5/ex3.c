// ex3.c: Lession 5 - exercise 3
//
// Example on two dimensional dynamically allocated array
//
// Windows: cl /Od /Zi ex3.c
// Linux: gcc -O2 ex3.c -o ex3
//
// -or- make TARGET=ex3
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void PrintVowels (char *pc)
{
  if (pc != NULL) {
    while (*pc++) {
      if (strchr("aeiou", *pc)) {
        printf ("%c", *pc);
      }
    }
  }
}

void main (void)
{
  char szStr[] = "Hello on the bathroom";

  printf ("%s\n", szStr);
  PrintVowels (szStr);
}


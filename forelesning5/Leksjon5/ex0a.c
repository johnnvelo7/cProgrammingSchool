// ex0b.c: Lession 5 - examples
//
// Example on two dimensional dynamically allocated array the C11 way.
//
// Windows: cl /Od /Zi ex0b.c
// Linux: gcc -std=C11 -O2 ex0b.c -o ex0b
//
// -or- make TARGET=ex6b
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main (void)
{
  int iRows = 5, iCols = 5;
  int iArray[iRows][iCols], i, j, k;

  // Accessing the array:
  for (i = 0; i < iRows; i++) {
    for (j = 0; j < iCols; j++) {
      iArray[i][j] = i * j;  // Setting a value
      k = iArray[i][j];      // Getting a value;
      printf ("%2d ", k);
    }
    printf ("\n");
  }

}

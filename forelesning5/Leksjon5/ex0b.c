// ex0b.c: Lession 5 - examples
//
// Example on two dimensional dynamically allocated array
//
// Windows: cl /Od /Zi ex0b.c
// Linux: gcc -O2 ex0b.c -o ex0b
//
// -or- make TARGET=ex6b
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main (void)
{
  int **iArray, i, j, k;
  int iRows = 5, iCols = 5, iRes;

  do {
    printf ("\nEnter rows, cols: ");
    iRes = scanf("%d, %d", &iRows, &iCols);
  }
  while (iRes != 2);

  // Allocate first the rows as an int* array:
  iArray = (int **) malloc (iRows * sizeof(int *));
  for (i = 0; i < iRows; i++) {
    // For each row, allocate the columns as int arrays:
    iArray[i] = (int *) malloc (iCols * sizeof(int));
  }

  // Accessing the array:
  for (i = 0; i < iRows; i++) {
    for (j = 0; j < iCols; j++) {
      iArray[i][j] = i * j;  // Setting a value
      k = iArray[i][j];      // Getting a value;
      printf ("%2d ", k);
    }
    printf ("\n");
  }

  // Free'ing the memory used by the array:
  for (i = 0; i < iRows; i++) {
    // For each row, free the columns:
    free(iArray[i]);
  }
  // Then free the row pointer array itself:
  free(iArray);
}

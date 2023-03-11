// ex1.c: Lession 5 - exercise 1
//
// Example on two dimensional dynamically allocated array
// The BubbleSort() is taken as-is from Lesson4/ex4.c:
//
// Windows: cl /Od /Zi ex1.c
// Linux: gcc -O2 ex1.c -o ex1
//
// -or- make TARGET=ex1
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Use preprocessor defines to make more readable constants:

#define FALSE 0
#define TRUE  1

// Taken as-is from Lesson4/ex4.c:
void BubbleSort (int aiArray[], int iSze);
void Swap (int *pi, int *pj);
void PrintArray (int aiArray[], int iSze);

// Predecl on new functions:
int **AllocateArray (int iRows, int iCols);
void FreeArray (int **aiArray, int iRows);
void GetRow (int aiArray[], int iCols, int iRow);

int main (void)
{
  int **aiArray, i, j;
  int iRows = 5, iCols = 5,
      iRes = 0, iRow = 0,
      iFreeRows = 0;

  do {
    printf ("\nEnter rows, cols (minimum 2, 2): ");
    iRes = scanf("%d, %d", &iRows, &iCols);
  }
  while (iRes != 2 && (iRows < 2) && (iCols < 2));

  iCols += 1;  // Adding extra column to use column 0 as "taken" flag.

  aiArray = AllocateArray (iRows, iCols);
  if (aiArray == NULL) return 1;

  // Setting all elements to 0.
  // Not really needed - see memset() in AllocateArray().

  for (i = 0; i < iRows; i++) {
    for (j = 0; j < iCols; j++) {
      aiArray[i][j] = 0;
    }
  }

  srand (time(NULL));         // A simple seed to random numbers

  iRow = rand() % iRows;      // Calculate a random row 0..iRows
  iFreeRows = iRows;

  #define FREE  0
  #define TAKEN 1

  while (iFreeRows > 0) {
    if (aiArray[iRow][0] == FREE) {               // Test if row is free ...
      GetRow(&aiArray[iRow][1], iCols - 1, iRow); // Get data from user and fill in row
      aiArray[iRow][0] = TAKEN;                   // Mark row taken.
      iFreeRows--;
    }
    else {
      iRow = (iRow + 1) % iRows;
    }
  }

  printf ("All arrays filled in:\n");
  for (iRow = 0; iRow < iRows; iRow++) {
    printf ("%2d: ", iRow);
    PrintArray(&aiArray[iRow][1], iCols - 1);
  }

  iRow = rand() % iRows; // Calculate a random row 0..iRows
  printf ("\nRow %d unsorted:\n%2d: ", iRow, iRow);
  PrintArray(&aiArray[iRow][1], iCols - 1);

  BubbleSort(&aiArray[iRow][1], iCols - 1); // Sort the row

  printf ("\nRow %d sorted:\n%2d: ", iRow, iRow);
  PrintArray(&aiArray[iRow][1], iCols - 1);

  FreeArray (aiArray, iRows);
  return 0;
}

// Make two-dimensional array of ints, return pointer:

int **AllocateArray (int iRows, int iCols)
{
  int **aiArray = NULL;
  // Allocate first the rows as an int* array:
  aiArray = (int **) malloc (iRows * sizeof(int *));
  if (aiArray != NULL) {
    for (int i = 0; i < iRows; i++) {
      // For each row, allocate the columns as int arrays:
      aiArray[i] = (int *) malloc (iCols * sizeof(int));
      if (aiArray[i] == NULL) break;
      memset (aiArray[i], 0, iCols * sizeof(int));
    }
  }
  return aiArray;
}

// Destroy an array made by AllocateArray():

void FreeArray (int **aiArray, int iRows)
{
  // Free'ing the memory used by the array:
  for (int i = 0; i < iRows; i++) {
    // For each row, free the columns:
    free(aiArray[i]);
  }
  // Then free the row pointer array itself:
  free(aiArray);
}

// Input data from user, place it in given array:

void GetRow (int aiArray[], int iCols, int iRow)
{
  int iCol = 0, iRes = 0, iNum = 0;

  printf ("\nRow %d: Enter %d space separated numbers:\n", iRow, iCols - iCol);
  do {
    iRes = scanf("%d", &iNum);
    if (iRes) {
      aiArray[iCol++] = iNum;
    }
  } while (iRes && iCol < iCols);

}

// The rest is taken as-is from Lesson4/ex4.c:

// Run through the elements and swap when you find a[i-1] > a[i].
// Keep doing this until you cannot swap anymore.

void BubbleSort (int aiArray[], int iSze)
{
   int bHasSwapped = TRUE;
   while (bHasSwapped) {
      bHasSwapped = FALSE;
      for (int i = 1; i < iSze; i++) {
         if (aiArray[i-1] > aiArray[i]) {
            Swap (&aiArray[i-1], &aiArray[i]);
            bHasSwapped = TRUE;
            // PrintArray (aiArray, iSze);
         }
      }
   }
}

void Swap (int *pi, int *pj)
{
   int iTmp = *pi;
   *pi = *pj;
   *pj = iTmp;
}

void PrintArray (int aiArray[], int iSze)
{
   // printf ("%d: ", iSze);
   for (int i = 0; i < iSze; i++) {
      printf ("%2d ", aiArray[i]);
   }
   printf ("\n");
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// THE BUBBLE SORT FUNCTION

void BubbleSort(int *iRows, int iCols){
	int i, j, temp;
	for (i = 0; i < iCols - 1; i++){
		for (j = 0; j < iCols - i -1; j++){
			if (iRows[j] > iRows[j + 1]){
				temp = iRows[j];
				iRows[j] = iRows [j + 1];
				iRows[j + 1] = temp;
			}
		}
	}
}

int main (int argc, char *argv[]){

	int r, c, i, j, k = 0, count = 0;
	int **array;
	
	printf("Enter the row numbers: ");
	scanf("%d", &r);
	printf("Enter the column numbers: ");
	scanf("%d", &c);
	
	array = (int **)malloc(r * sizeof(int *));
	for (i = 0; i < r; i++){
		array[i] = (int *)malloc(c * sizeof(int));
	}

	srand(time(0));

	return 0;
}

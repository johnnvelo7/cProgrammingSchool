#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*void BubbleSort (char *apszArray[], int iSize);*/



int main (int argc, char *argv[]){


	PrintBoxes(argc, argv);
	
	return 0;
}

int PrintBoxes (int argc, char *argv[]){

	int iRows, iCols;
	int *pR, *pC;
	pR = &iRows;
	pC = &iCols;
	
	printf("Please enter two numbers with space in between: ");
	scanf("%d %d", pR, pC);
	
	/*int iRows = 5, iCols = 5;
	int iArray[iRows][iCols], i, j, k; */
	printf("%d, %d \n", *pR, *pC);
	
	//accessing the array:
	int iArray[iRows][iCols], i, j, k;
	for (i = 0; i < iRows; i++){
		for(j = 0; j < iCols; j++){
			iArray[i][j] = i * j;
			k = iArray[i][j];
			printf("%2d ", k);
		}
		printf("\n");
	}
	return 0;

}

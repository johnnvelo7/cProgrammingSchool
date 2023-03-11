#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* void BubbleSort (char *apszArray[], int iSize); */


int main (int argc, char *argv[]){

	int iRows = 5, iCols = 5;
	int input;
	int *pI;
	pI = &input;
	
	
	printf("Hello please type a number: \n");
	scanf("%d", pI);
	int iArray[iRows][iCols], i, j, k;
	
	//accessing the array:
	for (i = 0; i < iRows; i++){
		for(j = 0; j < iCols; j++){
			printf("%2d", iArray[iRows][iCols]);			
		}
		printf("\n");
	}
	return 0;
}

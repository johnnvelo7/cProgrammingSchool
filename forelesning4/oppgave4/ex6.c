#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BubbleSort (char *apszArray[], int iSize);
void PrintArray (char *apszArray[], int iSize);
void Swap (char **ppA, char **ppB); //pointer pointer

int main (int iArgC, char *apszArgV[]){

	if (iArgC < 2){
		printf("Usage: ex6 <string1> <string2> <string3> <stringN>\n");
		return 1; //to check that the command line arg is valid
	}
	
	//calling the functions
	BubbleSort (&apszArgV[1], iArgC - 1); //sort arrays
	PrintArray (&apszArgV[1], iArgC - 1); //prints the arrays

	return 0;
}

#define FALSE 0
#define TRUE (!0)

//Functions

void BubbleSort (char *apszArray[], int iSize){

	int bHasSwapped = TRUE;
	while (bHasSwapped){
		bHasSwapped = FALSE;
		for (int i = 1; i < iSize; i++){
			if(strcmp(apszArray[i-1], apszArray[i]) > 0){
				Swap (&apszArray[i-1], &apszArray[i]);
				bHasSwapped = TRUE;
				//Print array (apszArray, iSize)
			}
		}
	}
}

//This is the sorting algorithm
void Swap (char **ppA, char **ppB){
	char *pTemp;
	pTemp = *ppA;
	*ppA = *ppB;
	*ppB = pTemp; 

}

void PrintArray (char *apszArray[], int iSize){
	printf("Number of strings are: %d \n", iSize);
	for (int i = 0; i < iSize; i++){
		printf("%d: %s\n", i, apszArray[i]);
		}
}

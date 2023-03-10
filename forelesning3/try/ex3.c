#include <stdio.h>
#include <stdlib.h>

int main (int iArgc, char *apszArgV[]){
	
	int iNum = 0;
	
	if (iArgc < 2) { //number of arguments is less than 2 
		printf ("Usage: ex3 'number'\n");
		return 1;
	}
	
	iNum = atoi(apszArgV[1]); //alphabet to integer
	if (iNum == 0){
		printf("Please enter a non zero argument\n");
		return 1;
	}
	
	if ((iNum % 2) == 0){ //if divided by 2 and remainder is 0
		printf("Numer %d is read and it is even.\n", iNum);
	} else {
		printf("Numer %d is read and it is odd.\n", iNum);
	}

	return 0;
}

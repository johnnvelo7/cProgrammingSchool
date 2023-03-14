#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int iArgC, char *apszArgV[]){

	if (iArgC < 2) {
	
		printf("Usage: ./writebinary <filename>\n");
		return 1; 
		
	}

	FILE *fileName; //pointer to file
	
	fileName = fopen (apszArgV[1], "wb");
	if (fileName != NULL) { //If there is a file 
		for (int i = 0; i < 100; i++){
			double lfNum = (double)i;
			fwrite (&lfNum, sizeof(double), 1, fileName);
		}
		fclose(fileName);
	}

	return 0;
}

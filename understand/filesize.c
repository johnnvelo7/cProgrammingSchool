#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main (int iArgC, char *apszArgV[]){

	long lineSize = 0;
	FILE *fileName; //pointer for file 
	
	// File size of an open file:
	
	if (iArgC < 2) {
		printf("YO WTF DONT YOU KNOW HOW TO USE THIS ?\n");
		return 1;
	}
	
	fileName = fopen(apszArgV[1], "r");
	if (fileName != NULL){
		if (fseek (fileName, 0, SEEK_END) == 0){
			lineSize = ftell(fileName);
			printf("Size of file: %d bytes.\n", lineSize);
			rewind(fileName);
		}
		fclose(fileName);
	}
	return 0;
}

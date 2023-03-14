#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int iArgC, char *apszArgV[]){

	if (iArgC < 2){
	
		printf("Usage: ./bintotxt <file_nameBinary> <file_nameText>\n");
		return 1;
	}

	FILE *fileBinary, *fileText;
	double lfNum = 0.0; //long float
	
	fileBinary = fopen(apszArgV[1], "rb");
	if (fileBinary != NULL) {
		fileText = fopen (apszArgV[2], "w");
		if (fileText != NULL){
			while (!feof(fileBinary)){
				if (fread(&lfNum, sizeof(double), 1, fileBinary) == 1){
					fprintf (fileText, "%lf\n", lfNum);
				}
			}
			fclose(fileText);
		}
		fclose(fileBinary);
	}	
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int iArgC, char *apszArgV[]){

	FILE *ptr; //pointer
	char ch;
	ptr = fopen("smallbook.txt", "r");
	
	if (ptr == NULL){
		printf("File cannot be opened.\n");
	}
	printf("Contents of this file are: \n");
	
	while (!feof(ptr)){
		ch = fgetc(ptr);
		printf("%c", ch);
	}
	fclose(ptr);

	return 0;
}


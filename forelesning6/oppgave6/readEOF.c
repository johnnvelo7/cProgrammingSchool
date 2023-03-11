#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int iArgC, char *apszArgV[]){

	FILE *ptr;
	char ch;
	
	ptr = fopen("smallbook.txt", "r"); //r for read
	
	if (ptr == NULL){
		printf("file can't be opened\n");	
	}
	
	printf("Contents of this file are: \n");
	
	do {
		ch = fgetc(ptr);
		printf("%c", ch);
	}
	
	while (ch != EOF);
	
	fclose(ptr);

	return 0;
}


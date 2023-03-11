#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int iArgC, char *apszArgV[]){

	FILE *ptr; //pointer
	char str[50];
	ptr = fopen ("smallbook.txt", "r");
	
	if (ptr == NULL){
		printf("Cannot real file bitch.\n");
	}
	printf("Contents of this file is: \n");
	
	while (fgets(str, 50, ptr) != NULL){
		printf("%s", str);
	}
	
	fclose(ptr);

	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int iArgC, char *apszArgV[]){

	FILE *fileName;
	char ch[256];
	fileName = fopen("newtext.txt", "r");
	printf("%s\n", fgets(ch, 20, fileName));
	
	fclose(fileName);


}

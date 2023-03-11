#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int iArgC, char *apszArgV[]){

	FILE *ptr = fopen("smallbook.txt", "r");
	if (ptr == NULL) {
		printf("no such file madafaka");
		return 1;
	}
	
	char buf[100];
	while (fscanf(ptr, "%s"))

	return 0;
}


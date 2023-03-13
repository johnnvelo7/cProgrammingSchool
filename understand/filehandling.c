#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int iArgC, char *apszArgV[]){

	FILE *fp;
	fp = fopen("smalltext.txt", "w");
	
	
	fprintf(fp, "%s", "Hello tangina tlgaa diba?.");
	
	
	fclose(fp);

	return 0;
}


/* STEPS

1. Declare a File pointer variable
2. Open a file using fopen(); 
3. Process the file using the suitable func 
4. Closing the file using the fclose(); 

*/ 

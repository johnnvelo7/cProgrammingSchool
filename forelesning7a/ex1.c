#include <stdio.h>
#include "pgdbglog.h"

static int glob_bTraceEnabled = 1;

int CountFunction () {
	
	static int count = 0; //static variable to retain value between function calls
	count++; //Increment the count number each time it is called
	return count; //Returns the current count	
}

int main (int iArgC, char *apszArgV[]){

	printf("Function has been called %d times.\n", CountFunction());
	pgdebug("Test");
	printf("Function has been called %d times.\n", CountFunction());
	pgerror("Malloc failed madfaka.\n");
	printf("Function has been called %d times.\n", CountFunction());
	printf("Function has been called %d times.\n", CountFunction());
	return 0;
	
	
	
}

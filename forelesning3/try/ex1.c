#include <stdio.h>

//void fordi den returnerer ingenting 
void main (void) {

	//variabler
	char c;
	int i;
	long li;
	float f;
	double df;
	
	//pointers 
	char *pc;
	int *pi;
	long *pl;
	float *pf;
	double *pd;
	void *pv; // pointer for void?
	
	int ia[20]; //int array ?
	
	//ALL PRINT STATEMENTS SIZE OF VARIABLES 
	printf("The size of char is %d.\n", (int)sizeof(c));
	printf("The size of int is %d.\n", (int)sizeof(i));
	printf("The size of long is %d.\n", (int)sizeof(li));
	printf("The size of float is %d.\n", (int)sizeof(f));
	printf("The size of double is %d.\n", (int)sizeof(df));
	
	//ALL PRINT STATEMENTS SIZE OF POINTERS
	printf("The size of char* is %d.\n", (int)sizeof(pc));
	printf("The size of int* is %d.\n", (int)sizeof(pi));
	printf("The size of long* is %d.\n", (int)sizeof(pl));
	printf("The size of float* is %d.\n", (int)sizeof(pf));
	printf("The size of double* is %d.\n", (int)sizeof(pd));
	
	//The size of void 
	printf("The size of void* is %d.\n", (int)sizeof(pv));
	
	//The size of array
	printf("The size of int array [20] is %d.\n", (int)sizeof(ia));
	
}

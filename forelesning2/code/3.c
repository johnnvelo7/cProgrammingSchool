#define MEMSIZE 10
#include <stdlib.h>

int main(int argc, char *argv[]){ 
	//My first buggy program
	while(1)
	printf("Entering main\n");
	int *array;
	int alpha, beta; 
	array = (int*)calloc(MEMSIZE,sizeof(int));
	array[5] = array[2]+10;
	alpha = MEMSIZE + 20;
	beta = alpha + MEMSIZE + 30;
	free(array);
 }

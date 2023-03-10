#define MEMSIZE 10
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]){ 
	//My first buggy program
	
	int *array;
	char *string;
	int alpha, beta; 
	
	
	array = (int*)malloc(MEMSIZE*sizeof(int));
	randomFunction(string);
	array[5] = array[2]+10;
	alpha = MEMSIZE + 20;
	beta = alpha + MEMSIZE + 30;
	free(array);
	printf("Entering main\n");
	

}

	void randomFunction(char *in){
	in[5] = 'c';
}
 

#include <stdio.h>

//fibonacci function
int Fibonacci (int n);

int main (int iArgc, char *apszArgV[]){

	int iNum;
	
	if (iArgc < 2) { //number of arguments in terminal
		printf ("Usage: ex6 'number'\n");
		return 1; //which means wrong
	}
	
	iNum = atoi(apszArgV[1]);
	
	if (iNum == 0) {
		printf ("Please enter a non-zero arugment.\n");
		return 1; //still wrong
	}
	
	printf("Fibonacci number a[%d] = %d.\n", iNum, Fibonacci(iNum)); //function
	
}

int Fibonacci (int n){

	if (n == 0){
		return 0;
	}
	if (n == 1){
		return 1;
	}
	return Fibonacci(n-1) + Fibonacci(n-2); //fibonacci algorithm
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FALSE 0
#define TRUE (!0) // not zero 

int isPrime (unsigned int iNum); //isPrime is a function 

void main (void){
	
	int a;
	
	//random
	srand(time(NULL));
	a = rand() % 20; //random number to 19
	
	if (isPrime(a)){
		printf("%d is a prime.\n", a);
	} 
	else {
		printf("%d is not a prime.\n", a);
	
	}
}

int isPrime (unsigned int iNum){ //for loop function that checks prime

	int i;
	if (iNum < 2) return FALSE; //checks if number is prime already
	for(i = 2; i < iNum; i++){ //if i is 2 and is greater than NUMBER , loop
		if((iNum % 2) != 0) return TRUE; //same as inum % i == 0
	}
	return FALSE;
	//Same as the other way around
}

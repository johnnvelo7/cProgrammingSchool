#include <stdio.h>
#include <stdlib.h>

/* 

	1. Local Variables (Used only in functions)
	2. Global Variables (Used everywhere, DONT DO GLOBAL)
	3. Function Parameters (Arguments in function)

*/


int main (int iArgC, char *apszArgV[]){

	// LOCAL VARIABLES INSIDE FUNCTION
	
	int x, y, z;
	
	x = 10;
	y = x + 5;
	z = y + 1;

	int a = 5, b = 5;
	int times = 5;
	int counter = 1;
	while (counter <= times){
	
		printf("C while loops: %d\n", counter);
		counter++;
	}
	
	printf("a = %d b = %d\n", a--, --b);
	printf("Value of Z = %d.\n", z);

	return 0;
}

#include <stdio.h>

int main(void)

{

	/* static array */
	
	int intArray[20];

	char charType;
	int intType;
	long longType;
	float floatType;
	double doubleType; 
	
	
	/* funksjonen */
	
	printf("Size of int array is: %d\n", (int) sizeof(intArray));
	printf("Size of char type is: %d\n", (int) sizeof(charType));
	printf("Size of int type is: %d\n", (int) sizeof(intType));
	printf("Size of long type is: %d\n", (int) sizeof(longType));
	printf("Size of floatType type is: %d\n", (int) sizeof(floatType));
	printf("Size of double type is: %d\n", (int) sizeof(doubleType));
	
	return 0;
}

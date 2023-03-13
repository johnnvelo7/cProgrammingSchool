#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct store different data types in diff location
// Union store different data types in same location

struct __courses {
	
	char Website[50];
	char Subject[50];
	int Price;
} courses;

union __Data {

	int i;
	float f;
	char str[10];
	
} Data;



int main (int iArgC, char *apszArgV[]){

	Data.i = 5;
	Data.f = 2.3;
	printf("The value of i is: %.2f\n", Data.f);

	return 0;
}

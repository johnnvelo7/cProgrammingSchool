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

int main (int iArgC, char *apszArgV[]){

	strcpy(courses.Website,"Hello");
	courses.Price = 20;
	
	printf("Message was: %s\n", courses.Website);
	printf("Price was: %d\n", courses.Price);

	return 0;
}

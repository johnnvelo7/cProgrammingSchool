#include <stdio.h>
#include <string.h>


int main (int iArgC, char *apszArgV[]){

	int var1 = 20;
	int *ip = &var1;
	char var2[10];

	char first_name[] = "John";
	char last_name[] = "Velo";
	
	char strFull_name[20];
	
	printf("The first name is: %s\n", first_name);
	printf("The last name is: %s\n", last_name);
	
	strcat(first_name, last_name);
	
	printf("Full name is: %s\n", first_name); //it adds first parameter to 2nd
	// to print the output, use the first parameter
	
	 //first parameter is dest, 2nd is source string
	
	return 0;
}

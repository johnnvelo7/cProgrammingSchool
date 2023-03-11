#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argvs[]){

	//Asking the user for the name
	char str[30];
	printf("Please enter the name here: ");
	fgets(str, sizeof(str), stdin);
	
	//Printing the name
	printf("Your name is: %s", str);
	

	return 0;
	
}

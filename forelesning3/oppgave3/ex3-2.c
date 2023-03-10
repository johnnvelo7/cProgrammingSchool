#include <stdio.h>

int main (int iArgC, char *apszArgV[])
{
	int iNum = 0;
	
	if (iArgC < 2) {
		printf("Usage: ex3 <number>\n");
		return 1;
	}
	
	iNum = atoi(apszArgV[1]);
	if (iNum == 0){
		printf("Please enter a non-zero argument.\n");
		return 1;
	}
	
	if ((iNum % 2) == 0){
		printf("Number %d is even.\n", iNum);
	}
	else {
		printf("Number %d is odd.\n", iNum);
	}
	
	return 0;
}

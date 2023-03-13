#include <stdio.h>

int totalValueOfArray(int size, int numberArray[]);

int main (int iArgC, char *apszArgV[]){
	
	int myNumberArray[6] = {23,30,21,18,17,25};
	int sum = totalValueOfArray(6, myNumberArray);
	
	printf("The total is: %d\n", sum);

	return 0;
}

//func parameter depends on you. as long as you use them correctly in the main
int totalValueOfArray(int size, int numberArray[]){

	int total = 0;
	for (int i = 0; i < size; i++){
		total += numberArray[i]; // same as total = total + numberArray[i];
	}
	return total;
}

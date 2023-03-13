#include <stdio.h>

int main (int iArgC, char *apszArgV[]){
	/*
	int inumArray[5] = {1,2,3,4,5};
	
	for(int i = 0; i<5;i++){
		printf("i = %d and num = %d\n", i, inumArray[i]);
	}
	*/
	
	int inumArray[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};
	
	inumArray[2][3] = 12;
	
	
	for(int row = 0; row < 3; row++){
		for(int column = 0; column < 4; column++){
			printf("value = %d.\n", inumArray[row][column]);
		}
		printf("\n");
	}
	return 0;
}

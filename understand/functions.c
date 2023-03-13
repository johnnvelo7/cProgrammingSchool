#include <stdio.h>
//	Call by reference (pointer)



int addition(int *num1, int *num2);

int main (int iArgC, char *apszArgV[]){

	int answer;
	int num1 = 5;
	int num2 = 10;
	
	answer = addition(&num1,&num2);
	printf("The total is: %d\n", answer);

	return 0;
}

//Func definition
int addition(int *a, int *b){
	*a = 6;
	return *a + *b;
}
/*

	Call by value

*/

/*
//Fun declaration
int addition(int num1, int num2);

int main (int iArgC, char *apszArgV[]){

	int answer;
	int num1 = 5;
	int num2 = 10;
	
	answer = addition(num1,num2);
	printf("The total is: %d\n", answer);

	return 0;
}

//Func definition
int addition(int a, int b){
	return a + b;
}

*/




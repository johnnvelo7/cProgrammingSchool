#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define NOT_GOOD 1
/*
	This code is now working for both -> and struct, but not "typedef"

 */

typedef struct _Person {
    char name[50];
    int age;
} Person;


int main (int iArgC, char *apszArgV[]){

	Person *pPerson = malloc(sizeof(struct _Person));
	strcpy(pPerson->name, "John"); //Name of Struct Person through pointer
	pPerson->age = 30; //Age of Struct person through pointer
	
			// pPerson->variable changes the value inside the struct!!
	
	//strcpy(Person.name, "Sabrina");
	//Person.age = 28;

	printf("Name is: %s, and the age is %d.\n", pPerson->name, pPerson->age);
	free(pPerson);
	//printf("Name is: %s, and the age is %d.\n", Person.name, Person.age);

	return 0;
}


/* 
A very short example of pointers in C 

int thisVariable = 5;
int thatVariable = 3;
thisVariable = thisVariable + thatVariable;
printf("%d\n", thisVariable); // prints 8



*/

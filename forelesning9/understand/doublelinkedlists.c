#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node *pNext;
	struct node *pPrev;
};

int main (int iArgC, char *apszArgV[]){

	//Initializeing nodes 
	struct node *head = NULL;
	struct node *one = NULL;
	struct node *two = NULL;
	struct node *three = NULL;
	
	//Allocating memory
	one = malloc(sizeof(struct node));
	two = malloc(sizeof(struct node));
	three = malloc(sizeof(struct node));
	
	//Assigning data values
	one->data = 1;
	two->data = 2;
	three->data = 3;
	
	//Connecting nodes
	one->pNext = two;
	one->pPrev = NULL;
	two->pNext = three;
	two->pPrev = one;
	three->pNext = NULL;
	three->pPrev = two;
	
	//Save address of first node in head
	head = one;
	
	//Printing
	printf("%d %d %d\n", one->data, two->data, three->data);
	
	//free
	free(one);
	free(two);
	free(three);

	return 0;
}

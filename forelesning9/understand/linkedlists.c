#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//IN THIS EXAMPLE HE MADE POINTER PER LIST

//creating nodes 

struct node {
	int data;
	struct node *next; //creating next
};

int main (int iArgC, char *apszArgV[]){
	//Initializing nodes
	struct node *head = NULL;
	struct node *one = NULL;
	struct node *two = NULL;
	struct node *three = NULL;
	
	//Alocating memory 
	one = malloc(sizeof(struct node));
	two = malloc(sizeof(struct node));
	three = malloc(sizeof(struct node));
	
	//Assigning data values
	one->data = 1;
	two->data = 2;
	three->data = 3;
	
	//connecting nodes
	one->next = two;
	two->next = three;
	three->next = NULL;
	
	//Saving address of first node in head
	head = one;

	printf("%d %d %d\n", one->data,two->data,three->data);
	free(one);
	free(two);
	free(three);

	return 0;
}

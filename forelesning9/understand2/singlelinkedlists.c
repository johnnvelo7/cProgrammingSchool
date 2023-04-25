#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link; //the pointer pointing to the struct node
};

int main (int iArgC, char *apszArgV[]){

	//we create a new pointer for head 
	struct node *head = (struct node *)malloc(sizeof(struct node));
	head->data = 45;
	head->link = NULL;
	
	struct node *current = (struct node *)malloc(sizeof(struct node));
	current->data = 98;
	current->link = NULL;
	head->link = current;
	
	current = (struct node *)malloc(sizeof(struct node));
	current->data = 3;
	current->link = NULL;
	
	head->link->link = current;
	printf("%d\n", current->data);
	
	free(head);
	free(current);
	
	return 0;
}

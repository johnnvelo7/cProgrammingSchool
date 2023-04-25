#include <stdio.h> //standard input output
#include <stdlib.h> //melloc function to create memory
#include <string.h>

//Creating the node

struct node {
	int data; //could be any data
	struct node *link; //*link points to struct node
};



int main (int iArgC, char *apszArgV[]){
	struct node *head = NULL;
	head = (struct node *)malloc(sizeof(struct node));
	
	head->data = 45;
	head->link = NULL;
	printf("%d\n", head->data);
	
	return 0;
}

//CREATING A WHOLE LINKED LISTS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	struct node *pPrev;
	int data;
	struct node *pNext;
};

struct node *addToEmptyList(struct node *pHead, int data){
	struct node *temp = malloc(sizeof(struct node));
	temp->pPrev = NULL;
	temp->data = data;
	temp->pNext = NULL;
	pHead = temp;
	return pHead;
}

struct node *addAtTheEnd(struct node *pHead, int data){
	struct node *temp, *tp;
	temp = malloc(sizeof(struct node));
	temp->pPrev = NULL;
	temp->data = data;
	temp->pNext = NULL;
	tp = pHead;
	while (tp->pNext != NULL)
		tp = tp->pNext;
	tp->pNext = temp;
	temp->pPrev = tp;
	return pHead;
}

struct node *createlist(struct node *pHead){
	int n, data, i;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	
	if (n == 0)
		return pHead;
	
	printf("Enter the element for the node 1: ");
	scanf("%d", &data);
	pHead = addToEmptyList(pHead, data);
	
	for(i = 1; i<n; i++){
		printf("Enter the element for the node %d: ", i+1);
		scanf("%d", &data);
		pHead = addAtTheEnd(pHead, data);
	}
	return pHead;
}

int main (int iArgC, char *apszArgV[]){

	struct node *pHead = NULL;
	struct node *ptr;
	pHead = createlist(pHead);
	
	ptr = pHead;
	while(ptr != NULL){
		printf("%d \n", ptr->data);
		ptr = ptr->pNext;
	}
	return 0;
}

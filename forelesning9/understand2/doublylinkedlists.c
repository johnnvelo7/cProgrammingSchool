#include <stdio.h>
#include <stdlib.h>


typedef struct _NODE { //USE THE SAME NAME OF STRUCT WHEN MAKING A PTR
	struct _NODE *pPrev;
	int data;
	struct _NODE *pNext;
} node_t;

//function to add a node to an empty list
node_t *addToEmptyList(node_t *pHead, int data){
	node_t *tmp = malloc(sizeof(node_t));
	tmp->pPrev = NULL;
	tmp->data = data;
	tmp->pNext = NULL;
	pHead = tmp;
	return pHead;
}
//function to add a node to at the beginning of the list
node_t *addToBeginning(node_t *pHead, int data){
	node_t *tmp = malloc(sizeof(node_t));
	tmp->pPrev = NULL;
	tmp->data = data;
	tmp->pNext = NULL;
	tmp->pNext = pHead;
	pHead->pPrev = tmp;
	pHead = tmp;
	return pHead;
}

//Function to add at the end
node_t *addAtTheEnd(node_t *pHead, int data){
	node_t *tmp, *tp;
	tmp = malloc(sizeof(node_t));
	tmp->pPrev = NULL;
	tmp->data = data;
	tmp->pNext = NULL;
	tp = pHead;
	while(tp->pNext != NULL){
		tp = tp->pNext;
	tp->pNext = tmp;
	tmp->pPrev = tp;
	return pHead; 
	}
}
//free the allocated memories
void freelist(node_t *pHead){
	node_t *current = pHead;
	while (current != NULL){
		node_t *pNext = current->pNext;
		free(current);
		current = pNext;
	}
}

int main (int iArgC, char *apszArgV[]){
	
	node_t *pHead = NULL;
	node_t *ptr;
	pHead = addToEmptyList(pHead, 45);
	pHead = addToBeginning(pHead, 57);
	pHead = addAtTheEnd(pHead, 9);
	
	ptr = pHead;
	while(ptr != NULL){
		printf("%d\n", ptr->data);
		ptr = ptr->pNext;
	}
	freelist(pHead);
	return 0;
}

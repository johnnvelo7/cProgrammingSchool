//DELETING THE FIRST AND THE LAST NODE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	struct node *pPrev;
	int data;
	struct node *pNext;
} node_T;

node_T *addToEmptyList(node_T *pHead, int data){
	node_T *pTemp = malloc(sizeof(node_T));
	pTemp->pPrev = NULL;
	pTemp->data = data;
	pTemp->pNext = NULL;
	pHead = pTemp;
	return pHead;
}

node_T *addAtTheEnd(node_T *pHead, int data){
	node_T *pTemp, *tp;
	pTemp = malloc(sizeof(node_T));
	pTemp->pPrev = NULL;
	pTemp->data = data;
	pTemp->pNext = NULL;
	tp = pHead;
	while (tp->pNext != NULL)
		tp = tp->pNext;
	tp->pNext = pTemp;
	pTemp->pPrev = tp;
	return pHead;
}

node_T *deleteFirst(node_T *pHead){
	node_T *pTemp = pHead;
	pHead = pHead->pNext;
	free(pTemp);
	pTemp = NULL;
	pHead->pPrev = NULL;
	return pHead;	
}

node_T *deleteLast(node_T *pHead){
	node_T *pTemp = pHead;
	node_T *pTemp2;
	while (pTemp->pNext != NULL)
		pTemp = pTemp->pNext;
	pTemp2 = pTemp->pPrev;
	pTemp2->pNext = NULL;
	free(pTemp);
	return pHead;
}

void print(node_T *pHead){
	node_T *ptr = pHead;
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->pNext;
	}
	printf("\n");
}

void freeList(node_T *pHead){
	node_T *ptr = pHead;
	while(ptr != NULL){
		node_T *pTemp = ptr;
		ptr = ptr->pNext;
		free(pTemp);
	}
}


int main (int iArgC, char *apszArgV[]){
	node_T *pHead = NULL;
	node_T *ptr;
	pHead = addToEmptyList(pHead, 34);
	pHead = addAtTheEnd(pHead, 45);
	pHead = addAtTheEnd(pHead, 9);
	
	printf("Before deletion: \n");
	print(pHead);
	
	pHead = deleteFirst(pHead);
	printf("After deletion: \n");
	print(pHead);
	
	pHead = deleteLast(pHead);
	printf("After deleting last.\n");
	print(pHead);
	
	freeList(pHead);
	
	return 0;
}

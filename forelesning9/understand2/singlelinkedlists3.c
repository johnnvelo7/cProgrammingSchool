#include <stdlib.h>
#include <stdio.h>

typedef struct _NODE {
    int value;
    struct _NODE *pNext;
} node_t;

//Prints the value of whats inside the list
void printlist(node_t *pHead) {
    node_t *temp = pHead;
    while (temp != NULL) {
        printf("%d - ", temp->value);
        temp = temp->pNext;
    }
    printf("\n");
}
//free the allocated memories 
void freelist(node_t *pHead){
	node_t *tmp = pHead;
	while (tmp != NULL){
		node_t *pNext = tmp->pNext;
		free(tmp);
		tmp = pNext;
	}
}
//This is create a new node function
node_t *create_new_node(int value){ //same as inside struct, as well pointer function
	node_t *result = malloc(sizeof(node_t));
	result->value = value;
	result->pNext = NULL;
	return result;
}

//Insert at head function using pointer to pointer
node_t *insert_at_head(node_t **pHead, node_t *node_to_insert){
	node_to_insert->pNext = *pHead;
	*pHead = node_to_insert;
	return node_to_insert;
}

//Insert after a node
void insert_after_node(node_t *node_to_insert_after, node_t *new_node){
	new_node->pNext = node_to_insert_after->pNext;
	node_to_insert_after->pNext = new_node;
}

//find a node 
node_t *find_node(node_t *pHead, int value){
	node_t *tmp = pHead;
	while(tmp != NULL){
		if (tmp->value == value) return tmp;
		tmp = tmp->pNext;
	}
	return NULL;
}


int main(int iArgC, char *apszArgV[]) {
	node_t *pHead = NULL;
   node_t *tmp;
   for (int i = 0; i < 25; i++){
   	tmp = create_new_node(i);
   	pHead = insert_at_head(&pHead, tmp);
   }
  	tmp = find_node(pHead, 13);
  	printf("Found node with value %d\n", tmp->value);
  	insert_after_node(tmp, create_new_node(75)); // in here, tmp = 13
  	printlist(pHead);
  	freelist(pHead);
   return 0;
}


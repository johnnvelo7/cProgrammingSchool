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

int main(int iArgC, char *apszArgV[]) {
    node_t *pHead, *n1, *n2, *n3; // BECAUSE I USED *n1 it became a pointer. Now You need to use -> to access it. 
    pHead = NULL;
    n1 = malloc(sizeof(node_t));
    n2 = malloc(sizeof(node_t));
    n3 = malloc(sizeof(node_t));
   

    // Assigning data value
    n1->value = 45;
    n2->value = 8;
    n3->value = 32;

    // link them up
        pHead = n1;
    n1->pNext = n2; //since it was *n2, n2 = now means &n2
    n2->pNext = n3;
    n3->pNext = NULL;
    
    //NEW VALUE EXAMPLE
    node_t *n4;
    n4 = malloc(sizeof(node_t));
    n4->value = 13;
    n4->pNext = n3; //its in the middle, before n3
    n2->pNext = n4; // after n2
	 
	 pHead = pHead->pNext; //This will delete the first node because the node is now starting on the second one: n2

    printlist(pHead);
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    
    return 0;
}


//ADDING AND STUFF
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
    tmp->pNext = pHead;
    if(pHead != NULL) {
        pHead->pPrev = tmp;
    }
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
    if(pHead == NULL){
        pHead = tmp;
    } else {
        tp = pHead;
        while(tp->pNext != NULL){
            tp = tp->pNext;
        }
        tp->pNext = tmp;
        tmp->pPrev = tp;
    }
    return pHead;
}

//Function to add in the middle
node_t *addAfterPosition(node_t *pHead, int data, int position){
    node_t *newP = NULL;
    node_t *tmp = pHead;
    node_t *tmp2 = NULL;
    newP = malloc(sizeof(node_t));
    newP->pPrev = NULL;
    newP->data = data;
    newP->pNext = NULL;
    if(position == 1){
        newP->pNext = pHead;
        if(pHead != NULL){
            pHead->pPrev = newP;
        }
        pHead = newP;
    } else {
        while (position > 1 && tmp != NULL){
            tmp = tmp->pNext;
            position--;
        }
        if (tmp == NULL){
            printf("Invalid position\n");
            free(newP);
        } else {
            tmp2 = tmp->pNext;
            tmp->pNext = newP;
            newP->pPrev = tmp;
            newP->pNext = tmp2;
            if(tmp2 != NULL){
                tmp2->pPrev = newP;
            }
        }
    }
    return pHead;
}
//Function to add in the middle
node_t *addAfterPosition2(node_t *pHead, int data, int position2){
    node_t *newP = NULL;
    node_t *tmp = pHead;
    node_t *tmp2 = NULL;
    newP = malloc(sizeof(node_t));
    newP->pPrev = NULL;
    newP->data = data;
    newP->pNext = NULL;
    if(position2 == 1){
        newP->pNext = pHead;
        if(pHead != NULL){
            pHead->pPrev = newP;
        }
        pHead = newP;
    } else {
        while (position2 > 2 && tmp != NULL){
            tmp = tmp->pNext;
            position2--;
        }
        if (tmp == NULL){
            printf("Invalid position\n");
            free(newP);
        } else {
            tmp2 = tmp->pNext;
            tmp->pNext = newP;
            newP->pPrev = tmp;
            newP->pNext = tmp2;
            if(tmp2 != NULL){
                tmp2->pPrev = newP;
            }
        }
    }
    return pHead;
}

//function to free the allocated memories
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
    int position = 2;
    int position2 = 3;
    pHead = addToEmptyList(pHead, 45);
    pHead = addToBeginning(pHead, 57);
    pHead = addAtTheEnd(pHead, 9);
    pHead = addAfterPosition(pHead, 25, position);
    pHead = addAfterPosition(pHead, 26, position2);
    ptr = pHead;
    while(ptr != NULL){
      printf("%d\n", ptr->data);
		ptr = ptr->pNext;
	}
	freelist(pHead);
	return 0;
}

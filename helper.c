/* Functions Background */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "knight.h"

int *createArray (int x){
	int *arr = NULL;
	arr = calloc (x, sizeof (int *));
	if (arr == NULL){
		printf("Error malloc\n");
		exit(EXIT_FAILURE);
	}
	return arr;
}

int **create2Darray (int r, int c){
	int i;
	int **arr = malloc (r*sizeof (int *)); 
	for (i = 0; i < r; i++){
		arr[i] = createArray (c);
	}
	return arr;
}

void free2Darray (int r, int c, int **arr){
	int i;
	for (i = 0; i < r; i++){
		free (arr[i]);
	}
	free(arr);
	return;
}

List newEmptyList() {
	return NULL;
}

List addItem(List li, State n) {
	List newList = malloc(sizeof(struct ListNode));
	assert(newList!=NULL);
	newList->item = n;
	newList->next = li;
	return newList;
}

List insertInOrder(List li, State new) {
	if ( li==NULL || new.sum < li->item.sum ) {
		return addItem(li,new);
	} 
	if ( li->item.sum < new.sum ) {
		li->next = insertInOrder(li->next,new);
	}
	return li;
}

State createNewState (State old, coords new, coords goal){
	
}

void listEmptyError() {
	printf("list empty\n");
	abort();
}

List removeFirstNode(List li) {
	List returnList;
	if ( li == NULL ) {
		listEmptyError();
	}
	returnList = li->next;
	free(li);
	return returnList;
}

State dequeue (List *li){
	
}


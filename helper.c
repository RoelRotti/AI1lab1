/* Functions Background */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
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

void markVisited (int **arr, coords c){
	arr[c.y][c.x] = 1;
} 

int hasBeenVisited (int **arr, coords c){
	if (arr[c.y][c.x]){
		return 1;
	}
	return 0;
}

coords createCoords (int c, int r){
	coords new;
	new.x = c;
	new.y = r;
	return new;
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

List insertInOrder(List li, State new) { /* Heuristic 1: Inserting in order based on diagonal distance to goal */
	if ( li==NULL || new.sum < li->item.sum ) {
		return addItem(li,new);
	} 
	if ( li->item.sum < new.sum ) {
		li->next = insertInOrder(li->next,new);
	}
	return li;
}

int calcDiagonal(coords new, coords goal){
	return sqrt(((goal.x-new.x)^2)+((goal.y-new.y)^2));
}

State createNewState (State old, coords new, coords goal){
	State newState;
	newState.currSt = new;
	newState.length = old.length+1;
	newState.diagonal = calcDiagonal(new, goal);
	newState.sum = newState.length+newState.diagonal;
	return newState;
}

State dequeue (List *li){
	State item = (*li)->item;
	*li = (*li)->next;
	return item;
}


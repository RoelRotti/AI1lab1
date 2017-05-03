/* Functions Background */

#include <stdio.h>
#include <stdlib.h>
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

List insertInOrder(list li, int n) {
	if ( li==NULL || n < li->item ) {
		return addItem(li,n);
	} 
	/* now li->item <= n */
	if ( li->item < n ) {
		li->next = insertInOrder(li->next,n);
	}
	return li;
}

State dequeue (List *li){
	State item = li->item;
	li = li->next;
	return item;
}


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

List addItem(int n, List li) {
	List newList = malloc(sizeof(struct ListNode));
	assert(newList!=NULL);
	newList->item = n;
	newList->next = li;
	return newList;
}


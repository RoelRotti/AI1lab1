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

/*
int checkIfNear(int Xcurrent, int Ycurrent, int Xgoal, int Ygoal){
	// Returns amount of steps needed to get to the goal (within range 0-3) and -1 if the solution is not near
	switch(Xcurrent-XGoal){
		case 2 :
		// the goal state is two columns to the left of Xcurrent
			switch(Ycurrent-YGoal){
				case -1 :
				//the goal state is one row above Xcurrent
					return 1;
					break;
				case 0 :
				//the goal state is on the same row
					return 2;
					break;
				case 1 :
				//the goal state is one row below Xcurrent
					return 1;
					break;
		}
		case 1 :
		// the goal state is one column to the left of Xcurrent
			switch(Ycurrent-YGoal){
				case -2 :
				//the goal state is two rows above Xcurrent
					return 1;
					break;
				case -1 :
				//the goal state is one row above Xcurrent
					return 2;
					break;
				case 0 :
				//the goal state is on the same row
					return 3;
					break;
				case 1 :
				//the goal state is one row below Xcurrent
					return 2;
					break;
				case 2 :
				//the goal state is two rows below Xcurrent
					return 1;
					break;
		}
		case 0 :
		// the goal state is in the same column as Xcurrent
			switch(Ycurrent-YGoal){
				case -2 :
				//the goal state is two rows above Xcurrent
					return 2;
					break;
				case -1 :
				//the goal state is one row above Xcurrent
					return 3;
					break;
				case 0 :
				//the goal state is on the same row
					return 0;
					break;
				case 1 :
				//the goal state is one row below Xcurrent
					return 3;
					break;
				case 2 :
				//the goal state is two rows below Xcurrent
					return 2;
					break;
		}
		case -1 :
		// the goal state is one column to the right of Xcurrent
				switch(Ycurrent-YGoal){
				case -2 :
				//the goal state is two rows above Xcurrent
					return 1;
					break;
				case -1 :
				//the goal state is one row above Xcurrent
					return 2;
					break;
				case 0 :
				//the goal state is on the same row
					return 3;
					break;
				case 1 :
				//the goal state is one row below Xcurrent
					return 2;
					break;
				case 2 :
				//the goal state is two rows below Xcurrent
					return 1;
					break;
		}
		case -2 :
		// the goal state is two columns to the right of Xcurrent
			switch(Ycurrent-YGoal){
				case -1 :
				//the goal state is one row above Xcurrent
					return 1;
					break;
				case 0 :
				//the goal state is on the same row
					return 2;
					break;
				case 1 :
				//the goal state is one row below Xcurrent
					return 1;
					break;
		}
	}
	return -1; 
}
*/


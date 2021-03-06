/* Functions Background */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "knight.h"

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

List insertInOrder(List li, State new) { 
	if ( li==NULL || new.sum < li->item.sum ) {
		return addItem(li,new);
	} 
	if ( li->item.sum < new.sum ) {
		li->next = insertInOrder(li->next,new);
	}
	return li;
}

int manhattanDistance (coords new, coords goal){
	return abs(goal.x-new.x)+abs(goal.y-new.y);
}

int calcDiagonal(coords new, coords goal){
	return sqrt(pow(abs(goal.x-new.x),2)+pow(abs(goal.y-new.y),2)); 
	/* sqare root of [(absolute value of distance x)^(absolute value of distance x) + (absolute value of distance y)^(absolute value of distance y)] */
}

int mazeCount (int n, int m, int **arr){
	int i, ii, counter = 0;
	for (i=0; i<n; i++){
		for (ii=0; ii<m; ii++){
			if (arr[i][ii] != 0){
				counter++;
			}
		}
	}
	return counter;
}

State createNewState (State old, coords new, coords goal, int heur){
	State newState;
	newState.currSt = new;
	newState.length = old.length+1;
	if (heur == 1){
		newState.diagonal = calcDiagonal(new, goal);
	} else if (heur == 2){
		newState.diagonal = manhattanDistance(new, goal);
	}
	newState.sum = newState.length+newState.diagonal;
	return newState;
}

State dequeue (List li){
	State item = (li)->item;
	return item;
}

List removeFirstItem (List li){
	List new = li->next;
	free(li);
	return new;
}

void freeList(List li) {
	List li1;
	while ( li != NULL ) {
		li1 = li->next;
		free(li);
		li = li1;
	}
	return;
}

int checkIfNear(int Xcurrent, int Ycurrent, int XGoal, int YGoal){
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

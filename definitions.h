/* Definitions for Knight-Program  */

#ifndef KNIGHT_H
#define	KNIGHT_H

typedef struct coordinates {
	int x;
	int y;
} coords;

typedef struct State { 	
	coords currSt;	/* contains the coordinates of the current State in the maze */
	int length; 	/* length of path until this state */
	int diagonal;
	int sum;
} State;

typedef struct ListNode *List;
  
typedef struct ListNode {
  State item;
  List next;
} ListNode;


coords createCoords (int c, int r);
List newEmptyList();
List addItem(List li, State n);
List insertInOrder(List li, State new);
int mazeCount (int n, int m, int **arr);
int calcDiagonal(coords new, coords goal);
int manhattanDistance (coords new, coords goal);
State createNewState (State old, coords new, coords goal, int heur);
State dequeue (List li);
void freeList(List li);
List removeFirstItem (List li);
int checkIfNear(int Xcurrent, int Ycurrent, int Xgoal, int Ygoal);

#endif	/* DEFINITIONS_H */

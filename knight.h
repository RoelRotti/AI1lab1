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


int *createArray (int x); 												/* Array-related Functions */
int **create2Darray (int r, int c);
void scanArray (int k, int hg, int hf, int *people);
void scan2Darray (int r, int c, int **small, int **large, int **medium);
void free2Darray (int r, int c, int **arr);
	
#endif	/* DEFINITIONS_H */



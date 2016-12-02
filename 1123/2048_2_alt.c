#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifdef ONLINE_JUDGE
int getseed(){
    return 0;
}
#else
#include <time.h>
int getseed(){
    return time(NULL);
}
#endif

typedef struct _board {
    int tile[4][4];
    struct _board *next;
} board;

void print_board(board *a) {
    int i,j;
    printf("-----------------------------\n");
    for (i = 0; i < 4; ++i) {
	printf("|      |      |      |      |\n|");
	for (j = 0; j < 4; ++j) {
	    if (a->tile[i][j] == 0) printf("      |");
	    else printf("%6d|", a->tile[i][j]);
	}
	printf("\n|      |      |      |      |\n");
	printf("-----------------------------\n");
    }
    return;
}

/* randomly select a blank and put 2 in it. */
void add2(board *a) {
    int i, j;
    int n, N = 0;
    for (i = 0; i < 4; ++i) {
	for (j = 0; j < 4; ++j) {
	    if (a->tile[i][j] == 0) N++;
	}
    }
    if (N == 0) return;
    n = rand() % N;
    for (i = 0; i < 4; ++i) {
	for (j = 0; j < 4; ++j) {
	    if (a->tile[i][j] == 0) {
		if (n == 0) {
		    a->tile[i][j] = 2;
		    i = j = 4;
		}
		else n--;
	    }
	}
    }
    return;
}

// direction is right to left, i.e. n0 <- n1 <- n2 <- n3
void pack(int *n0, int *n1, int *n2, int *n3)
{
    int num[4] = { *n0, *n1, *n2, *n3 };
    int i, z;

    // find index of first 0
    for (z=0; z<3 && num[z]!=0; z++) ;

    if (z >= 3) return;	// nothing to do

    for (i=z+1; i<4; i++) {
	if (num[i] != 0) {
	    num[z] = num[i];
	    num[i] = 0;
	    z++;
	}
    }

    // write back
    *n0 = num[0]; *n1 = num[1]; *n2 = num[2]; *n3 = num[3];
}

// direction is right to left, i.e. n0 <- n1 <- n2 <- n3
void merge(int *n0, int *n1, int *n2, int *n3)
{
    int num[4] = { *n0, *n1, *n2, *n3 };
    int i;

    for (i=0; i<3; i++) {
	if (num[i] == num[i+1]) {
	    num[i] *= 2;
	    num[i+1] = 0;
	    i++;
	}
    }

    // write back
    *n0 = num[0]; *n1 = num[1]; *n2 = num[2]; *n3 = num[3];
}

// pack, merge and pack again
void pack_merge_pack(int *n0, int *n1, int *n2, int *n3)
{
    pack(n0, n1, n2, n3);
    merge(n0, n1, n2, n3);
    pack(n0, n1, n2, n3);
}

// create a new board with a move
board *next_board(board *bd, char move)
{
    board *nb = malloc(sizeof(board));
    int i;

    *nb = *bd;
    nb->next = bd;

    if (move == 'w') {	    // upward
	for (i=0; i<4; i++)
	    pack_merge_pack( &(nb->tile[0][i]), &(nb->tile[1][i]), &(nb->tile[2][i]), &(nb->tile[3][i]));
    }
    else if (move == 'a') { // to the left
	for (i=0; i<4; i++)
	    pack_merge_pack( &(nb->tile[i][0]), &(nb->tile[i][1]), &(nb->tile[i][2]), &(nb->tile[i][3]));
    }
    else if (move == 's') { // downward
	for (i=0; i<4; i++)
	    pack_merge_pack( &(nb->tile[3][i]), &(nb->tile[2][i]), &(nb->tile[1][i]), &(nb->tile[0][i]));
    }
    else if (move == 'd') { // to the right
	for (i=0; i<4; i++)
	    pack_merge_pack( &(nb->tile[i][3]), &(nb->tile[i][2]), &(nb->tile[i][1]), &(nb->tile[i][0]));
    }

    return nb;
}

int main()
{
    board *curr;
    char com[10];

    srand(getseed());

    curr = (board *) calloc(1, sizeof(board));
    curr->tile[2][0] = 2;
    curr->tile[3][3] = 2;
    curr->next = (board *)NULL;

    while (1) {
	print_board(curr);

	scanf("%s", com);

	switch(com[0]){
	    case 'w':
	    case 'a':
	    case 's':
	    case 'd':
		curr = next_board(curr, com[0]);
		break;
	    case 'u':
		if (curr->next) {
		    board *del = curr;
		    curr = curr->next;
		    free(del);
		}
		break;
	    case 'q':
		return 0;
	}
	if (com[0] != 'u') {
	    add2(curr);
	}
    }

    return 0;
}

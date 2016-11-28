#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _board{
	int tile[4][4];
} board;

void print(board *a){
	int i,j;
	printf("-----------------------------\n");
	for(i = 0; i < 4; ++i){
		printf("|      |      |      |      |\n|");
		for(j = 0; j < 4; ++j){
			if(a->tile[i][j] == 0) printf("      |");
			else printf("%6d|", a->tile[i][j]);
		}
		printf("\n|      |      |      |      |\n");
		printf("-----------------------------\n");
	}
	return;
}

void merge_a(board *next)
{
    int i, j;
    for (i=0; i<4; i++)
    {
	for (j=0; j<3; j++)
	{
	    if (next->tile[i][j]==next->tile[i][j+1])
	    {
		next->tile[i][j] = 2*next->tile[i][j];
		next->tile[i][j+1] = 0;
	    }
	}
    }
}

void shift_a(board *before, board *after)
{
    int i, j, k;
    for (i=0; i<4; i++)
    {
	for (j=0; j<4; j++)
	    after->tile[i][j] = before->tile[i][j];	    
    }

    for (i=0; i<4; i++)
    {
	for (k=0; k<3; k++)
	{
	    for (j=0; j<3-k; j++)
	    {
		if (after->tile[i][j]==0)
		{
		    after->tile[i][j] = after->tile[i][j+1];
		    after->tile[i][j+1] = 0;
		}
	    }
	}
    }
}

void merge_d(board *next)
{
    int i, j;
    for (i=0; i<4; i++)
    {
	for (j=3; j>0; j--)
	{
	    if (next->tile[i][j]==next->tile[i][j-1])
	    {
		next->tile[i][j] = 2*next->tile[i][j];
		next->tile[i][j-1] = 0;
	    }
	}
    }
}

void shift_d(board *before, board *after)
{
    int i, j, k;
    for (i=0; i<4; i++)
    {
	for (j=0; j<4; j++)
	    after->tile[i][j] = before->tile[i][j];	    
    }

    for (i=0; i<4; i++)
    {
	for (k=0; k<3; k++)
	{
	    for (j=3; j>k; j--)
	    {
		if (after->tile[i][j]==0)
		{
		    after->tile[i][j] = after->tile[i][j-1];
		    after->tile[i][j-1] = 0;
		}
	    }
	}
    }
}

void merge_w(board *next)
{
    int i, j;
    for (j=0; j<4; j++)
    {
	for (i=0; i<3; i++)
	{
	    if (next->tile[i][j]==next->tile[i+1][j])
	    {
		next->tile[i][j] = 2*next->tile[i][j];
		next->tile[i+1][j] = 0;
	    }
	}
    }
}

void shift_w(board *before, board *after)
{
    int i, j, k;
    for (i=0; i<4; i++)
    {
	for (j=0; j<4; j++)
	    after->tile[i][j] = before->tile[i][j];	    
    }

    for (j=0; j<4; j++)
    {
	for (k=0; k<3; k++)
	{
	    for (i=0; i<3-k; i++)
	    {
		if (after->tile[i][j]==0)
		{
		    after->tile[i][j] = after->tile[i+1][j];
		    after->tile[i+1][j] = 0;
		}
	    }
	}
    }
}

void merge_s(board *next)
{
    int i, j;
    for (j=0; j<4; j++)
    {
	for (i=3; i>0; i--)
	{
	    if (next->tile[i][j]==next->tile[i-1][j])
	    {
		next->tile[i][j] = 2*next->tile[i][j];
		next->tile[i-1][j] = 0;
	    }
	}
    }
}

void shift_s(board *before, board *after)
{
    int i, j, k;
    for (i=0; i<4; i++)
    {
	for (j=0; j<4; j++)
	    after->tile[i][j] = before->tile[i][j];	    
    }

    for (j=0; j<4; j++)
    {
	for (k=0; k<3; k++)
	{
	    for (i=3; i>k; i--)
	    {
		if (after->tile[i][j]==0)
		{
		    after->tile[i][j] = after->tile[i-1][j];
		    after->tile[i-1][j] = 0;
		}
	    }
	}
    }
}
int main(){
	board *curr = (board *) malloc(sizeof(board));
	board *next;
	int n, N;
	int i, j, k;
	char com[10];
	scanf("%d", &N);
	for(i = 0; i < 4; ++i){
		for(j = 0; j < 4; ++j){
			scanf("%d", &curr->tile[i][j]);
		}
	}
	for(n = 0; n < N; ++n){
		print(curr);
		next = (board *) calloc(1, sizeof(board));
		scanf("%s", com);
		switch(com[0]){
		case 'w':
			shift_w(curr, next);
			merge_w(next);
			shift_w(next, next);
			break;
		case 'a':
			shift_a(curr, next);
			merge_a(next);
			shift_a(next, next);
			break;
		case 's':
			shift_s(curr, next);
			merge_s(next);
			shift_s(next, next);
			break;
		case 'd':
			shift_d(curr, next);
			merge_d(next);
			shift_d(next, next);
			break;
		}
		free(curr);
		curr = next;
	}
	print(curr);
	return 0;
}


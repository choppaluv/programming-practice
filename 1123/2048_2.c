#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifdef ONLINE_JUDGE
int getseed(){
	return 0;
}
#endif

#ifndef ONLINE_JUDGE
#include <time.h>
int getseed(){
	return time(NULL);
}
#endif

typedef struct _board{
	int tile[4][4];
} board;

typedef struct list{
    board *x;
    struct list *next;
}list;

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

/* randomly select a blank and put 2 in it. */
void add2(board *a){
	int i, j;
	int n, N = 0;
	for(i = 0; i < 4; ++i){
		for(j = 0; j < 4; ++j){
			if(a->tile[i][j] == 0) N++;
		}
	}
	if(N == 0) return;
	n = rand() % N;
	for(i = 0; i < 4; ++i){
		for(j = 0; j < 4; ++j){
			if(a->tile[i][j] == 0){
				if(n == 0){
					a->tile[i][j] = 2;
					i = j = 4;
				}
				else n--;
			}
		}
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

typedef struct stack{
    list *top;
    int num;
}stack;

void push(stack *s, board *b)
{
    list *ptr = (list *)malloc(sizeof(list));
    ptr->x = b;
    ptr->next = s->top;
    s->top = ptr;
    s->num++;
//    printf("pushed! num =%d\n",s->num);
}

board *pop(stack *s)
{
    list *ptr = (list *)malloc(sizeof(list));
    ptr = s->top;
    s->top = s->top->next;
    s->num--;
 //   printf("poped! num =%d\n",s->num);
    board *data = (board *)malloc(sizeof(board));
    data = ptr->x;
    free(ptr);
    return data;
}

int main(){
	board *curr = (board *) calloc(1, sizeof(board));
	board *first = (board *) calloc(1, sizeof(board));
	board *next;
	int n;
	int i, j, k;
	char com[10];
	char past[10];
	
	srand(getseed());
	curr->tile[2][0] = 2;
	curr->tile[3][3] = 2;

	list *head = (list *)malloc(sizeof(list));
	head->x = curr;
	head->next = NULL;
	first = curr;

	stack *s = (stack *)malloc(sizeof(stack));
	s->top = head;
	s->num = 1;

	while(1){
		print(curr);
		scanf("%s", com);
		if (com[0]!='u')
		{
		    next = (board *) calloc(1, sizeof(board));
		    push(s, next);
		}
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
		case 'u':
			if (s->num==1)
			{
			//    printf("num = 1");
			    curr = first;
			    break;
			}
/*			else if (s->num==2 && past[0]!='u')
			{
			    curr = pop(s);
			    pop(s);
			    push(s, curr);
			    break;
			}
			else if (s->num==2 && past[0]=='u')
			{
			    pop(s);
			    curr = pop(s);
			    push(s, curr);
			    break;
			}*/
			else if (past[0]=='u')
			{
//			    printf("also u!\n");
			    curr = pop(s);
			    break;
			}
			else if (s->num==2)
			{
			    pop(s);
			    curr = pop(s);
			    push(s,curr);
			    break;
			}
			else
			{
			    pop(s);
			    curr = pop(s);
			    break;
			}
		case 'q':
			return 0;
		}
		if(com[0] != 'u'){
			add2(next);
			curr = next;
		}
		strcpy(past, com);
	//	printf("past=%c\n", past[0]);
//		printf("com=%c\n", com[0]);
	}
}

#include <stdio.h>
#include <stdlib.h>

void snail_array(int **snail, int N)
{
    int i, j;
    if (N==1)
	snail[0][0] = 1;
    else if (N==0)
	return;
    else
    {
	snail_array(snail, N-2);
	for (i=N-2; i>=0; i--)
	    for (j=N-2; j>=0; j--)
		snail[i+1][j+1] = snail[i][j] + 4*N-4;
	for (i=0; i<N; i++)
	    snail[0][i] = i+1;
	for (j=1; j<N; j++)
	    snail[j][N-1] = j+N;
	for (i=1; i<N; i++)
	    snail[N-1][N-i-1] = 2*N-1+i;
	for (i=1; i<N-1; i++)
	    snail[N-1-i][0] = 3*N-2+i;
    }
}

void main()
{
    int N;
    scanf("%d", &N);

    int **snail = (int **)malloc(sizeof(int *)*N);
    int i, j;
    for (i=0; i<N; i++)
	snail[i] = (int *)malloc(sizeof(int)*N);
    
    snail_array(snail, N);
    for (i=0; i<N; i++)
    {
	for (j=0; j<N; j++)
	   printf("%d ", snail[i][j]);
	printf("\n"); 
    }
}

#include <stdio.h>
#include <stdlib.h>

int comb(int n, int k)
{
    if (k==0 || n==k)
	return 1;
    else
	return comb(n-1,k-1)+comb(n-1,k);
}

int horizontal(int **board, int N)
{
    int cnt, sum=0;
    int i, j;
    for (i=0; i<N; i++)
    {
	cnt = 0;
	for (j=0; j<N; j++)
	    if (board[i][j] == 1)
		cnt++;
	if (cnt>1)
	    sum += comb(cnt,2);
    }
//    printf("%d\n", sum);
    return sum;
}

int vertical(int **board, int N)
{
    int cnt, sum=0;
    int i, j;
    for (j=0; j<N; j++)
    {
	cnt = 0;
	for (i=0; i<N; i++)
	{
	    if (board[i][j] == 1)
	    {
		cnt++;
//		printf("cnt=%d\n",cnt);
	    }
	}
	if (cnt>1)
	    sum += comb(cnt,2);
    }
//    printf("%d\n", sum);
    return sum;
}

int cross(int **board, int N)
{
    int i, k;
    int cnt, sum = 0;
    for (k=0; k<N; k++)
    {
	cnt = 0;
	for (i=0; i<N && k-i>=0; i++)
	    if (board[i][k-i]==1)
		cnt++;
	if (cnt>1)
	    sum += comb(cnt,2);
    }
    for (k=N; k<2*N-1; k++)
    {
	cnt = 0;
	for (i=k-(N-1); i<N; i++)
	    if (board[i][k-i]==1)
		cnt++;
	if (cnt>1)
	    sum += comb(cnt,2);
    }
//    printf("%d\n", sum);
    return sum;
}

int cross2(int **board, int N)
{
    int i, k;
    int cnt, sum = 0;
    for (k=-(N-1); k<0; k++)
    {
	cnt = 0;
	for (i=0; i<k+N; i++) 
	{
	    if (board[i][i-k]==1)
		cnt++;
	}
	if (cnt>1)
	    sum += comb(cnt,2);
    }
    for (k=0; k<N; k++)
    {
	cnt = 0;
	for (i=k; i<N; i++)
	    if (board[i][i-k]==1)
		cnt++;
	if (cnt>1)
	    sum += comb(cnt,2);
    }
//    printf("%d\n", sum);
    return sum;
}

int main()
{
    int N;
    int sum = 0;

    scanf("%d\n", &N);

    int i;
    int **board;
    board = (int **) malloc(N * sizeof(int *));
    for (i=0; i<N; i++)
	board[i] = (int *) malloc(N * sizeof(int));

    char c;
    int j;

    for (i=0; i<N; i++)
    {
	for (j=0; j<N; j++)
	{
	    c = getchar();
	    if (c == 'Q')
		board[i][j] = 1;
	    else if (c == '.')
		board[i][j] = 0;
	}
	do {
	    c = getchar();
	} while (c != '\n');
    }
    
//    for (i=0; i<N; i++)
//    {
//	for (j=0; j<N; j++)
//	    printf("%d",board[i][j]);
//	printf("\n");
//    } 
    sum = horizontal(board, N) + vertical(board, N) + cross(board,N) + cross2(board,N);
    printf("%d\n", sum);

    for (i=0; i<N; i++)
    {
	free(board[i]);
    }
    free(board);
    return 0;
}

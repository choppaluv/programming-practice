#include <stdio.h>
#include <stdlib.h>

int comb(int n, int k)
{
    if (k==0 || n==k)
	return 1;
    else
	return comb(n-1,k-1)+comb(n-1,k);
}

int main()
{
    int N;

    scanf("%d\n", &N);

    int *row;
    int *col;
    int *diag0;
    int *diag1;
    row = (int *) calloc(N, sizeof(int));
    col = (int *) calloc(N, sizeof(int));
    diag0 = (int *) calloc(2*N-1, sizeof(int));	// diagonal /
    diag1 = (int *) calloc(2*N-1, sizeof(int));	// diagonal \

    char c;
    int i, j;

    for (i=0; i<N; i++)
    {
	for (j=0; j<N; j++)
	{
	    c = getchar();
	    if (c == 'Q') {
		row[i]++;
		col[j]++;
		diag0[i+j]++;
		diag1[N-1-i+j]++;
	    }
	}
	do { c = getchar(); } while (c != '\n');
    }

    int num_pair = 0;

    for (i=0; i<N; i++)
    {
	if (row[i] > 1)
	    num_pair += comb(row[i], 2);
	if (col[i] > 1)
	    num_pair += comb(col[i], 2);
    }

    for (i=0; i<2*N-1; i++)
    {
	if (diag0[i] > 1)
	    num_pair += comb(diag0[i], 2);
	if (diag1[i] > 1)
	    num_pair += comb(diag1[i], 2);
    }

    printf("%d\n", num_pair);

    return 0;
}

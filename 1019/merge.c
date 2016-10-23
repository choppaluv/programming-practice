#include <stdio.h>
int merge(int N, int M, int *A, int *B, int *C)
{
    int i=0, j=0;
    while (i<N && j<M)
    {
	if (A[i]>B[j])
	{
	    C[i+j] = B[j];
	    j++;
	}
	else
	{
	    C[i+j] = A[i];
	    i++;
	}
    }
    if (i==N)
	while (j<M)
	{
	    C[i+j] = B[j];
	    j++;
	}
    if (j==M)
	while (i<N)
	{
	    C[i+j] = A[i];
	    i++;
	}
    return 0;
}
int main()
{
    int N, M;
    int i,j;
    int A[1000001],B[1000001];
    scanf("%d %d", &N, &M);
    for (i=0; i<N; i++)
	scanf("%d", &A[i]);
    for (j=0; j<M; j++)
	scanf("%d", &B[j]);
    int C[N+M];
    merge(N,M,A,B,C);
    for (i=0; i<N+M; i++)
	printf("%d ",C[i]);
    return 0;
g

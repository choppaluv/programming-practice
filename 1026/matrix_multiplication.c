#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int **make_matrix(int N)
{
    int i;
    int **arr = NULL;
    arr = (int **) malloc(N * sizeof(int *));
    for (i=0; i<N; i++)
	arr[i] = (int *) malloc(N * sizeof(int));
    
    int c;
    int j;
    for (i=0; i<N; i++)
    {
	j=0;
	for (j=0; j<N; j++)
	    scanf("%d", &arr[i][j]);
    }
    return arr;
}

int mat_multiply(int N, int **mat1, int **mat2, int **arr)
{
    int i, j, k;
    for (i=0; i<N; i++)
    {
	for(j=0; j<N; j++)
	    arr[i][j]=0;
    }

    for (i=0; i<N; i++)
    {
	for(j=0; j<N; j++)
	{
	    for (k=0; k<N; k++)
		arr[i][j] += mat1[i][k] * mat2[k][j];
	}
    }
    return 0;
}

int main()
{
    int N;

    scanf("%d\n", &N);
    
    int **mat1;
    int **mat2;
    
    mat1 = make_matrix(N);
    mat2 = make_matrix(N);

    int i, j;
    int **arr = NULL;
    arr = (int **) malloc(N * sizeof(int *));
    for (i=0; i<N; i++)
	arr[i] = (int *) malloc(N * sizeof(int));

    mat_multiply(N, mat1, mat2, arr);

    for (i=0; i<N; i++)
    {
	for (j=0; j<N-1; j++)
	    printf("%d ", arr[i][j]);
	printf("%d", arr[i][N-1]);
	printf("\n");
    } 
    for(i=0; i<N; i++) {
	free(mat1[i]);
	free(mat2[i]);
	free(arr[i]);
    }

    free(mat1);
    free(mat2);
    free(arr);

    return 0;
}

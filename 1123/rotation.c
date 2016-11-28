#include <stdio.h>
#include <stdlib.h>

void rotation(int rot, int **array, int n, int m)
{
    int i, j;
    if (rot==0)
    {
	for (i=0; i<n; i++)
	{
	    for (j=0; j<m; j++)
		printf("%d ", array[i][j]);
	    printf("\n");
	}
	return;
    }
    else if (rot==1)
    {
	int **array2 = (int **)malloc(sizeof(int *)*m);
	for (i=0; i<m; i++)
	    array2[i] = (int *)malloc(sizeof(int)*n);
	for (i=0; i<m; i++)
	    for (j=0; j<n; j++)
		array2[i][j] = array[n-j-1][i];
	
	for (i=0; i<n; i++)
	    free(array[i]);
	free(array);
	for (i=0; i<m; i++)
	{
	    for (j=0; j<n; j++)
		printf("%d ", array2[i][j]);
	    printf("\n");
	}
	return;
    }
    else if (rot==2)
    {
	int **array3 = (int **)malloc(sizeof(int *)*n);
	for (i=0; i<n; i++)
	    array3[i] = (int *)malloc(sizeof(int)*m);
	for (i=0; i<n; i++)
	    for (j=0; j<m; j++)
		array3[i][j] = array[n-i-1][m-j-1];

	for (i=0; i<n; i++)
	    free(array[i]);
	free(array);
	for (i=0; i<n; i++)
	{
	    for (j=0; j<m; j++)
		printf("%d ", array3[i][j]);
	    printf("\n");
	}
	return;
    }
    else if (rot==3)
    {
	int **array4 = (int **)malloc(sizeof(int *)*m);
	for (i=0; i<m; i++)
	    array4[i] = (int *)malloc(sizeof(int)*n);
	
	for (i=0; i<m; i++)
	    for (j=0; j<n; j++)
		array4[i][j] = array[j][m-i-1];

	for(i=0; i<n; i++)
	    free(array[i]);
	free(array);
	for (i=0; i<m; i++)
	{
	    for (j=0; j<n; j++)
		printf("%d ", array4[i][j]);
	    printf("\n");
	}
	return;
    }
}

void main()
{
    int n, m;

    scanf("%d %d", &n, &m);
    int **array = (int **)malloc(sizeof(int *)*n);
    int i, j;
    for (i=0; i<n; i++)
	array[i] = (int *)malloc(sizeof(int)*m);

    for (i=0; i<n; i++)
	for (j=0; j<m; j++)
	    scanf("%d", &array[i][j]);

    int rot;
    scanf("%d", &rot);

    rotation(rot, array, n, m);
}

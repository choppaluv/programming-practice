#include <stdio.h>
#include <stdlib.h>

void binary_search(int array[], int x, int start, int end)
{
   // printf("[%d,%d]\n", start, end);

    if (start == end)
    {
	if (array[start] == x)
	    printf("%d ", start);
	else 
	    printf("-1 ");
    }
    else
    {
	int mid = (start+end)/2;
	if (array[mid] > x)
	{
	    if (mid>start)
		binary_search(array, x, start, mid-1);
	    else
		printf("-1 ");
	}
	else if (array[mid] == x)
	    printf("%d ", mid);
	else
	    binary_search(array, x, mid+1, end);
    }
}

void main()
{
    int N;
    int Q;
    int i;

    scanf("%d", &N);
    scanf("%d", &Q);
    
    int *array = (int *)malloc(sizeof(int)*N);
    int *integers = (int *)malloc(sizeof(int)*Q);

    for (i=0; i<N; i++)
    {
	scanf("%d", &array[i]);
	// printf("%d\n", array[i]);
    }
    for (i=0; i<Q; i++)
    {
	scanf("%d", &integers[i]);
	// printf("%d\n", integers[i]);
    }
    for (i=0; i<Q; i++)
	binary_search(array, integers[i], 0, N-1);
    
    free(array);
    free(integers);
}

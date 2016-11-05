#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int start1, int end1, int start2, int end2)
{
    int *tmp = malloc(sizeof(int)*(end2+1));
    int i = start1, j = start2, k =start1;
    while ( (i != end1+1) && (j != end2+1))
    {
	if (array[i] > array[j])
	    tmp[k++] = array[i++];
	else
	    tmp[k++] = array[j++];
    }
    if (i==end1+1)
    {
	for (i=j; i<=end2; i++)
	    tmp[k++] = array[i];
    }
    else if (j==end2+1)
    {
	for (j=i; j<=end1; j++)
	    tmp[k++] = array[j];
    }

    for (i=start1; i<=end2; i++)
	array[i] = tmp[i];

    free(tmp);
    return;
} 

void merge_sort(int array[], int start, int end)
{
    int mid;
    if (start==end)
    {
	return;
    }
    else
    {
	mid = (start + end)/2;
//	int array1[mid-start+1];
//	int array2[end-mid];
	merge_sort(array, start, mid);
//	int i;
//	for (i=0; i<(mid-start+1); i++)
//	    printf("%d\n", array1[i]);
	merge_sort(array, mid+1, end);    
	merge(array, start, mid, mid+1, end);
	return;
    }
}

int main()
{
    int N;
    int i;

    scanf("%d\n", &N);
    
    int *array = malloc(sizeof(int)*N);
    for (i=0; i<N; i++)
	scanf("%d", &array[i]);

    merge_sort(array, 0, N-1);

    for (i=0; i<N; i++)
	printf("%d ", array[i]); 

    free(array);
    return 0;
}

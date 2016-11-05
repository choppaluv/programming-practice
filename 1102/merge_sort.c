#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int start1, int end1, int start2, int end2, int  merged_array[])
{
    int i = start1, j = start2, k =start1;
    while ( (i != end1+1) && (j != end2+1))
    {
	if (array[i] > array[j])
	    merged_array[k++] = array[i++];
	else
	    merged_array[k++] = array[j++];
    }
    if (i==end1+1)
    {
	for (i=j; i<=end2; i++)
	    merged_array[k++] = array[i];
    }
    else if (j==end2+1)
    {
	for (j=i; j<=end1; j++)
	    merged_array[k++] = array[j];
    }

    for (i=start1; i<=end2; i++)
	array[i] = merged_array[i];
    return;
} 

void merge_sort(int array[], int start, int end, int merged_array[])
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
	merge_sort(array, start, mid, merged_array);
//	int i;
//	for (i=0; i<(mid-start+1); i++)
//	    printf("%d\n", array1[i]);
	merge_sort(array, mid+1, end, merged_array);    
	merge(array, start, mid, mid+1, end, merged_array);
	return;
    }
}

int main()
{
    int N;
    int i;

    scanf("%d\n", &N);
    
    int *array = malloc(sizeof(int)*N);
    int merged_array[N];
    for (i=0; i<N; i++)
	scanf("%d", &array[i]);

    merge_sort(array, 0, N-1, merged_array);

    for (i=0; i<N; i++)
	printf("%d ", merged_array[i]); 

    return 0;
}

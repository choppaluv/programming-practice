#include <stdio.h>
#include <stdlib.h>

void merge(char *array[], int start1, int end1, int start2, int end2, char *merged_array[])
{
    int i = start1, j = start2, k = start1;
    while ( (i!=end1+1) && (j!=end2+1) )
    {
	if (strcmp(array[i], array[j])>0)
	    merged_array[k++] = array[j++];
	else
	    merged_array[k++] = array[i++];
    }
    
    if (i==end1+1)
	for (i=j; i<=end2; i++)
	    merged_array[k++] = array[i];
    else if (j==end2+1)
	for (j=i; j<=end1; j++)
	    merged_array[k++] = array[j];

    for (i=start1; i<=end2; i++)
	array[i] = merged_array[i];

    return;
}
     
void sort(char *array[], int start, int end, char *merged_array[])
{
    int mid = (start+end)/2;
    if (start==end)
	return;
    else
    {
	sort(array, start, mid, merged_array);
	sort(array, mid+1, end, merged_array);
	merge(array, start, mid, mid+1, end, merged_array);
	return;
    }
}

int main()
{
    int N;
    scanf("%d\n", &N);

    char **array = (char**) malloc(sizeof(char*)*N);
    char **merged_array = (char**) malloc(sizeof(char*)*N);

    int i;
    for (i=0; i<N; i++)
    {
	array[i] = (char*) calloc(sizeof(char), 101);
	scanf("%s", array[i]);
    }

    sort(array, 0, N-1, merged_array);

    for (i=0; i<N; i++)
	printf("%s ", merged_array[i]);

    printf("\n");
    return 0;
}

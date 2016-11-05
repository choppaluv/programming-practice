#include <stdio.h>
#include <stdlib.h>

void merge(char *array[], int start1, int end1, int start2, int end2)
{
    int i = start1, j = start2, k = start1;
    char **tmp = (char **)malloc(sizeof(char*)*(end2+1));

    while ( (i!=end1+1) && (j!=end2+1) )
    {
	if (strcmp(array[i], array[j])>0)
	    tmp[k++] = array[j++];
	else
	    tmp[k++] = array[i++];
    }
    
    if (i==end1+1)
	for (i=j; i<=end2; i++)
	    tmp[k++] = array[i];
    else if (j==end2+1)
	for (j=i; j<=end1; j++)
	    tmp[k++] = array[j];

    for (i=start1; i<=end2; i++)
	array[i] = tmp[i];

    
    free(tmp);

    return;
}
     
void sort(char *array[], int start, int end)
{
    int mid = (start+end)/2;
    if (start==end)
	return;
    else
    {
	sort(array, start, mid);
	sort(array, mid+1, end);
	merge(array, start, mid, mid+1, end);
	return;
    }
}

int main()
{
    int N;
    scanf("%d\n", &N);

    char **array = (char**) malloc(sizeof(char*)*N);

    int i;
    for (i=0; i<N; i++)
    {
	array[i] = (char*) malloc(sizeof(char)* 101);
	scanf("%s", array[i]);
    }

    sort(array, 0, N-1);

    for (i=0; i<N; i++)
	printf("%s ", array[i]);

    printf("\n");

    for (i=0; i<N; i++)
	free(array[i]);

    free(array);
    return 0;
}

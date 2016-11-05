#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int insert(char word[], char *array[], int size)
{
    int i = 0;
    for(i=0; i<size; i++)
    {
	if (strcmp(word, array[i])==0)
	    return size;
    }
    array[size++] = word;
    return size;
}

int delete(char word[], char *array[], int size)
{
    int i = 0;
    int find = -1;
    for (i=0; i<size; i++)
	if (strcmp(word, array[i]) == 0)
	    find = i;
    if (find == -1)
	return size;
    for (i=find; i<size-1; i++)
	array[i] = array[i+1];
    return size-1;
}

void merge(char *array[], int start1, int end1, int start2, int end2)
{
    int i = start1, j = start2, k = start1;
    char **tmp = (char**)malloc(sizeof(char*)*(end2+1));
    while ((i!= end1+1) && (j!= end2+1))
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
}

void sort(char *array[], int start, int end)
{
    int mid = (start+end)/2;
    if (start==end)
	return;
    sort(array, start, mid);
    sort(array, mid+1, end);
    merge(array, start, mid, mid+1, end);
    return;
}

void find(char word[], char *array[], int size)
{
    if (size==0)
    {
	printf("-1\n");
	return;
    }
    sort(array, 0, size-1);
    int i;
    for (i=0; i<size; i++)
    {
	if (strcmp(word, array[i])==0)
	{
	    printf("%d\n", i);
	    return;
	}
    }
    printf("-1\n");
    return;
}

int  mod(char command[], char word[], char *array[], int size)
{
    if (strcmp(command, "insert")==0)
	size = insert(word, array, size);
    else if (strcmp(command, "delete")==0)
	size = delete(word, array, size);
    else if (strcmp(command, "find")==0)
	find(word, array, size);
    return size;
}

void print_array(char *array[], int size)
{
    if (size==0)
    {
	printf("\n");
	return;
    }
    sort(array, 0, size-1);
    int i;
    for (i=0; i<size; i++)
	printf("%s ", array[i]);
    printf("\n");
}

int main()
{
    int N;
    scanf("%d\n", &N);

    int i;
    char command[7];
    char **word = (char **)malloc(sizeof(char *)*20);
    for (i=0; i<20; i++)
	word[i] = (char *)malloc(sizeof(char)*1001);
    char *array[20];
    int size = 0;
    for (i=0; i<N; i++)
    {
	scanf("%s", command);
	if (strcmp(command,"print")!=0)
	{
	    scanf("%s", word[i]);
	    size = mod(command, word[i], array, size);
	}
	else
	    print_array(array, size);
    }
    return 0;
}

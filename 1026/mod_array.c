#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int get_query_line(char *arg[])
{
    char word[1000];
    char ch;
    int i = 0;
    int cnt = 0;

    while ((ch=getchar()) != EOF)
    {
	if (isspace(ch)) {
	    if (i > 0) {
		word[i] = '\0';
		arg[cnt++] = strdup(word);
		i = 0;
	    }
	    if (ch == '\n')
		break;
	}
	else
	    word[i++] = ch;
    }

    return cnt;
}

int exist(char *array[], char *word[], int size, int n) 
{
    int j;
    for (j=0; j<size; j++)
    {
	if (strcmp(word[n],array[j])==0)
	    return j;
    }	    
    return -1;
}

int insert(char *array[], char *word[], int size, int n)
{
    int i;
    for (i=1; i<n; i++)
    {
	if (exist(array, word, size, i) == -1)
	{
	    array[size++] = word[i];
	}
    }
    return size;
}

int delete(char *array[], char *arg[], int size, int n)
{
    int i, j;
    int cnt=0;
    int find;
    for (i=1; i<n; i++)
    {
	if ((find = exist(array, arg, size, i)) != -1)
	{
	    for (j=find; j<size-1; j++)
		array[j] = array[j+1];
	    size--;
	}
    }
    return size;
}

int sort(char *array[], int size)
{
    int i, j;
    for (i=0; i<size-1; i++)
	for(j=0;j<size-i-1; j++)
	{
	    if (strlen(array[j]) > strlen(array[j+1]))
	    {
		char *temp;
		temp = array[j];
		array[j] = array[j+1];
		array[j+1] = temp;
	    }
	    else if (strlen(array[j]) == strlen(array[j+1]))
	    {
		if (strcmp(array[j], array[j+1])>0)
		{
		    char *tmp;
		    tmp = array[j];
		    array[j] = array[j+1];
		    array[j+1] = tmp;
		}
	    }
	}
    return 0;
}

int find(char *array[], char *arg[], int size)
{
    int index;
    sort(array, size);
    index = exist(array, arg, size, 1);
    printf("%d\n", index);
    return 0;
}

void print(char *array[], int size)
{
    int i;
    sort(array, size);
    for (i=0; i<size; i++)
	if (i > 0)
	    printf(" %s", array[i]);
	else
	    printf("%s", array[i]);
    printf("\n");
}

int mod_array(char *array[], char *arg[], int size, int n)
{
//    printf("%s\n", arg[0]);
    if ((strcmp(arg[0], "insert")) == 0)
    {
	size = insert(array, arg, size, n);
	return size;
    }
    else if ((strcmp(arg[0], "delete")) == 0)
    {
	size = delete(array, arg, size, n);
	return size;
    }
    else if ((strcmp(arg[0], "find")) == 0)
    {
	find(array, arg, size);
	return size;
    }
    else if ((strcmp(arg[0], "print")) == 0)
    {
	print(array, size);
	return size;
    }
    else 
    {
	return -1;
    }
}

void main()
{
    char *arg[1000];
    char *array[100];
    int size = 0;

    int N;
    scanf("%d\n", &N);
   // printf("%d\n", N);

    int j;
    for (j=0; j<N; j++)
    {
	int n = get_query_line(arg);
//	printf("%d\n", n);
	int i;
	size = mod_array(array, arg, size, n);
	if (size == -1)
	    break;
/*	for (i=0; i<size; i++)
	    printf("%s\n", array[i]); */
    }
/*
    for (i=0; i<n; i++)
	printf("%s\n", arg[i]); */
}

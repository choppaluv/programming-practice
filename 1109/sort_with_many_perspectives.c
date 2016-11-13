#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[9];
    double height;
    int weight;
}student;


int name(student A[], int i)
{
    student tmp;
    int c;
    c = strcmp(A[i].name, A[i+1].name);
    if (c>0)
    {
	tmp = A[i+1];
	A[i+1] = A[i];
	A[i] = tmp;
	return 1;
    }
    else if (c==0)
	return 0;
    else
	return 1;
}

int height(student A[], int i)
{
    student tmp;
    if (A[i].height > A[i+1].height)
    {
	tmp = A[i+1];
	A[i+1] = A[i];
	A[i] = tmp;
	return 1;
    }
    else if (A[i].height == A[i+1].height)
	return 0;
    else
	return 1;
}

int weight(student A[], int i)
{
    student tmp;
    if (A[i].weight > A[i+1].weight)
    {
	tmp = A[i+1];
	A[i+1] = A[i];
	A[i] = tmp;
	return 1;
    }
    else if (A[i].weight==A[i+1].weight)
	return 0;
    else
	return 1;
}

void sort(int (*fun1)(student *, int), int (*fun2)(student *, int), int (*fun3)(student *, int), student A[], int N)
{
    int i, j;
    int c;
    for (j=N-1; j>0; j--)
    {
	for (i=0; i<j; i++)
	{
	    c = fun1(A, i);
	    if (c==0)
	    {
		c = fun2(A, i);
		if (c==0)
		    fun3(A, i);
	    }
	}
    }
    for (i=0; i<N; i++)
	printf("%s %.1f %d\n", A[i].name, A[i].height, A[i].weight);
}

int main()
{
    int N;
    scanf("%d", &N);
    int i;
/*    char **name = (char **)malloc(sizeof(char *)*N);
    for (i=0; i<N; i++)
	name[i] = (char *)malloc(sizeof(char)*9);

    double *height = (double *)malloc(sizeof(double)*N);
    int *weight = (int *)malloc(sizeof(int)*N); */
    student *contestants = (student *) malloc(sizeof(student)*N);

/*    int *sorted = (int *)malloc(sizeof(int)*N);
    for (i=0; i<N; i++)
    {
	sorted[i] = i;
    }*/

    for (i=0; i<N; i++)
	scanf("%s %lf %d", contestants[i].name, &contestants[i].height, &contestants[i].weight);

    sort(name, height, weight, contestants, N);
    sort(height, weight, name, contestants, N);
    sort(weight, name, height, contestants, N);
    return 0;
}

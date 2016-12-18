#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int insert(char **arr, char *word, int N)
{
	int i;
	for (i=0; i<N; i++)
		if (strcmp(word, arr[i])==0)
			return N;
	
	strcpy(arr[N], word);
	return N+1;
}

int delete(char **arr, char *word, int N)
{
	int i;
	int check = -1;
	for (i=0; i<N; i++)
		if (strcmp(word, arr[i])==0)
			check = i;

	if (check==-1) //do not exist
		return N;

	else 
	{
		for (i=check; i<N-1; i++)
			strcpy(arr[i], arr[i+1]);
	}

	return N-1;
}

void sort(char **arr, int N)
{
	int i, j;
	for (i=0; i<N; i++)
		for (j=0; j<N-i-1; j++)
		{
			if (strcmp(arr[j],arr[j+1])>0)
			{
				char *tmp;
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}

}

void find(char **arr, char *word, int N)
{
	int i;
	sort(arr, N);
	for (i=0; i<N; i++)
		if (strcmp(arr[i], word)==0)
		{
			printf("%d\n", i);
			return;
		}

	printf("-1\n");
}

void print(char **arr, int N)
{
	int i;
	sort(arr, N);
	for (i=0; i<N; i++)
	{
		printf("%s ", arr[i]);
	}
	printf("\n");
}

void main()
{
	int n;
	scanf("%d", &n);
	int i;
	char q[10];
	char word[101];

	int size = 0;
	char **arr = (char **)malloc(sizeof(char *)*100);
	for (i=0; i<100; i++)
		arr[i] = (char *)malloc(sizeof(char)*101);
	for (i=0; i<n; i++)
	{
		scanf("%s", q);
		if (strcmp(q, "insert")==0)
		{
			scanf("%s", word);
			size = insert(arr, word, size);
		}
		else if (strcmp(q, "delete")==0)
		{
			scanf("%s", word);
			size = delete(arr, word, size);
		}
		else if (strcmp(q, "find")==0)
		{
			scanf("%s", word);
			find(arr, word, size);
		}
		else if (strcmp(q, "print")==0)
		{
			print(arr, size);
		}
//			print(arr, size);
	}
	for (i=0; i<100; i++)
		free(arr[i]);

	free(arr);
}

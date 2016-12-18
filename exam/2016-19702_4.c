#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(char **target, char **pattern, int tar_w, int tar_h, int pat_w, int pat_h, int x, int y)
{
//	printf("row: %d, column:%d\n", y, x);
	int check=0;
	int j;
//	printf("target[j+y]+x :%s",target[j+y]+x);
	for (j=0; j<pat_h; j++)
		if (strncmp(target[j+y]+x,pattern[j], pat_w)==0) 
			check++;
	if (check==pat_h)
	{
		printf("%d %d\n", x,y);
		return 1;
	}
	else return 0;
}

void main()
{
	int tar_w, tar_h, pat_w, pat_h;
	scanf("%d %d", &tar_w, &tar_h);
	int i;
	char **target = (char **)malloc(sizeof(char *)*tar_h);
	for (i=0; i<tar_h; i++)
		target[i] = (char *)malloc(sizeof(char)*(tar_w+1));

	for (i=0; i<tar_h; i++)
		scanf("%s", target[i]);
	
	scanf("%d %d", &pat_w, &pat_h);
	char **pattern = (char **)malloc(sizeof(char *)*pat_h);
	for (i=0; i<pat_h; i++)
		pattern[i] = (char *)malloc(sizeof(char)*(pat_w+1));

	for (i=0; i<pat_h; i++)
		scanf("%s", pattern[i]);

	int check=0;
	int j;
	for (i=0; i<tar_w-pat_w+1; i++)
		for (j=0; j<tar_h-pat_h+1; j++)
		{
			check += comp(target, pattern, tar_w, tar_h, pat_w, pat_h, i, j);
//			printf("check=%d\n", check);
		}

	if (check==0)
		printf("-1\n");

	for (i=0; i<tar_h; i++)
		free(target[i]);
	free(target);
	for (i=0; i<pat_h; i++)
		free(pattern[i]);
	free(pattern);

}

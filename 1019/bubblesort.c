#include <stdio.h>
int bubble(int *sort, int N)
{
    int i, j ,temp;
    for (i=0;i<N;i++)
    {
	for (j=0;j<N-i-1;j++)
	{
	    if (sort[j]>sort[j+1])
	    {
		temp = sort[j];
		sort[j] = sort[j+1];
		sort[j+1] = temp;
	    }
	}
    }
    return 0;
}
int main()
{
    int i;
    int sort[10001];
    int N;
    scanf("%d",&N);
    for (i=0;i<N;i++)
	scanf("%d",&sort[i]);
    bubble(sort, N);
    for (i=0;i<N;i++)
	printf("%d ",sort[i]);
    return 0;
}

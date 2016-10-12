#include <stdio.h>
int main()
{
    int i=0, j=0, n;
    int score[1001], rank[1001];
    scanf("%d",&n);
    for (i=0;i<n; i++)
	scanf("%d",&score[i]);
	rank[i]=0;
    for (i=0;i<n;i++)
    {
	for (j=0;j<n;j++)
	{
	    if (score[i]<score[j])
		rank[i]++;
	}
	printf("%d ",rank[i]+1);
    }
    printf("\n");
    return 0;
}

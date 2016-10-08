#include <stdio.h>

int main()
{
    int n, m, i = 0, j = 0, k;
    
    scanf("%d",&n);
    m = n; 

    for (i=0; i<m; i++)
    {
	for (k=0; k<i; k++)
	{
	    printf(" ");
	}
	for (j=2*n-1; j>0; j--)
	{
	    printf("*");
	}
	for (k=0; k<i; k++)
	{
	    printf(" ");
	}
	printf("\n");
	n--;
    }
    n = m;
    for (i=1; i<n; i++)
    {
	for (k=m-2; k>0; k--)
	{
	    printf(" ");
	}
	for (j=0; j<2*i+1; j++)
	{
	    printf("*");
	}
	for (k=m-2; k>0; k--)
	{
	    printf(" ");
	}
	printf("\n");
	m--;
    }
    return 0;
}

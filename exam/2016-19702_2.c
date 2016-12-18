#include <stdio.h>

int comb(int n, int k)
{
	if (k==0 || n==k)
		return 1;
	else 
		return comb(n-1, k-1)+comb(n-1,k);
}

void main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int res;
	res = comb(n,k);
	printf("%d\n", res);
}

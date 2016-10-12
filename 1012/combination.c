#include <stdio.h>
long long comb(int n, int k)
{
    if (k==0 || n==k)
	return 1;
    else 
	return comb(n-1,k-1)+comb(n-1,k);
}
int main()
{
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    if (n<=20 && k>=0 && n>=k)
	printf("%lld\n",comb(n,k));
    else 
	printf("Input error\n");
    return 0;
}


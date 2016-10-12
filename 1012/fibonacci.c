#include <stdio.h>
long long fibo(int n)
{
    int i = 0;
    long long temp, fibo1 = 0, fibo2 = 1;
    for (i=0;i<n-1;i++)
    {
	temp = fibo1;
	fibo1 = fibo2;
	fibo2 = fibo1 + temp;

    }
    return fibo2;
}
int main()
{
    int n;

    scanf("%d",&n);

    if (n>0)
	printf("%lld\n",fibo(n));
    else
	printf("0\n");
    return 0;
}


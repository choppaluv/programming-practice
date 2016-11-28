#include <stdio.h>

#define MAXDEG 2222

typedef struct poly{
    int n;
    long long coeff[MAXDEG];
}poly;

void poly_mul(poly f, poly g, int n, int m)
{
    poly h;
    int i, j;
    for (i=0; i<n+m+1; i++)
	for (j=0; j<=i; j++)
	    h.coeff[i] += f.coeff[j] * g.coeff[i-j];
    for (i=0; i<n+m+1; i++)
	printf("%lld ", h.coeff[i]);
    printf("\n");
}

void main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    poly f, g;
    int i;
    for (i=0; i<n+1; i++)
	scanf("%lld", &f.coeff[i]);
    for (i=0; i<m+1; i++)
	scanf("%lld", &g.coeff[i]);

    poly_mul(f, g, n, m);
}


#include <stdio.h>

void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int change(int *A, int x, int y, int N)
{
    int i;
    for (i=0;i<N;i++)
    {
	if (A[i]==x)
	    A[i]=y;
    }
    return 0;
}

int shift(int *A, int x, int y)
{
    int temp, i;
    temp = A[y];
    for (i=y;i>x;i--)
	A[i]=A[i-1];
    A[x] = temp;
    return 0;
}

int sort(int *A, int x, int y)
{
    int i, j, temp;
    for (i=0;i<y-x;i++)
    {
	for (j=x;j<y;j++)
	{
	    if (A[j]>A[j+1])
	    {
		swap(&A[j],&A[j+1]);
	    }
	}
    }
     return 0;
}

int mod(int *A, int a, int x, int y, int N)
{
    switch(a)
    {
	case 0:
	    swap(&A[x],&A[y]);
	    break;
	case 1:
	    change(A,x,y,N);
	    break;
	case 2:
	    shift(A,x,y);
	    break;
	case 3:
	    sort(A,x,y);
	    break;
    }
    return 0;
}

void print_array(int *arr, int size)
{
    int i;

    for (i=0; i<size; i++)
	printf("%d ",arr[i]);
    putchar('\n');
}

int main()
{
    int N;
    int i, j;
    int M, a,x,y;

    scanf("%d",&N);

    int A[N];

    for (i=0;i<N;i++)
	scanf("%d",&A[i]);

    scanf("%d",&M);

    for (i=0;i<M;i++)
    {
	scanf("%d %d %d", &a, &x, &y);
	mod(A,a,x,y,N);
    }
    print_array(A, N);

    return 0;
}

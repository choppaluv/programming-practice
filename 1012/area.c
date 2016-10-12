#include <stdio.h>
int main()
{
    int n, i, j, k;
    int x[301], y[301];
    double max = 0, area;
    for (i=0;i<302;i++)
    {
	x[i] = 0;
	y[i] = 0;
    }
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
	scanf("%d",&x[i]);
	scanf("%d",&y[i]);
    }
    for (i=0;i<n;i++)
    {
	for (j=i+1;j<n;j++)
	{
	    for (k=j+1;k<n;k++)
	    {
		area = (double)(x[i]*y[j]+x[j]*y[k]+x[k]*y[i]-y[i]*x[j]-y[j]*x[k]-y[k]*x[i])/2;
		if (area<0)
		    area = -area;
		if (area>max)
		    max = area;
	    }
	}
    }
    printf("%.2f\n",max);
    return 0;
}

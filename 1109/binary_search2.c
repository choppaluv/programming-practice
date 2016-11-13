#include <stdio.h>
#include <math.h>

#define EPS 0.0000001

double function(double x)
{
    return x*pow(2.0,x);
}

void binary_search(double (*function) (double), double y, double start, double end)
{
    double mid = (start+end)/2;
   // printf("[%f,%f]", start, end);
    if ((function(mid)-y)<EPS && (y-function(mid))<EPS)
	printf("%f\n", mid);
    else
    {
	if (function(mid)>y)
	    binary_search(function, y, start, mid);
	else
	    binary_search(function, y, mid, end);
    }
}
void main()
{
    double y;
    scanf("%lf", &y);
    double max = 20*pow(2.0, 20.0);
    binary_search(function, y, 0, max); 
}

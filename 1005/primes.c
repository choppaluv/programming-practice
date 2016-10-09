#include <stdio.h>

int main() 
{
    int cnt = 0, i, j;
    
    for (i=2; i<1000; i++)
    {
	for (j=2; j<i; j++)
	{
	    if (i%j==0)
	    {
		cnt++;
		break;
	    }
	}
	if (cnt==0)
	    printf("%d\n",i);
	cnt=0;
    }	
    return 0;
}

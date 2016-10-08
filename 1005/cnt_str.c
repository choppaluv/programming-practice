#include <stdio.h>

int main() 
{
    char a[1001], b[1001];
    int i = 0, j = 0, k = 0, l = 0, cnt = 0, sizea = 0, sizeb = 0;	// minimize the use of single character variable

    scanf("%s", a);
    scanf("%s", b);
    
    while (a[sizea]!=0)
	sizea++;
    while (b[sizeb]!=0)
	sizeb++;
    while(1)
    {
	for (j=0; j<sizeb; j++)
	{
	    for (i=l; i<sizea; i++)
	    {
		if (a[i]==b[j])
		{
		    k++;
		    l = i +1;
		    break;	// sometimes 'break' helps to write concise code,
				// but be careful when you use it in nested loop like this case
		}
		else
		{
		    k = 0;
		}
	    }
	    if (k==sizeb)
	    {
		cnt++;
		k = 0;
	    }
	}
	if (i==sizea)
	    break;
    } 
    printf("%d", cnt);
    return 0;
}

#include <stdio.h>

int main() 
{
    char a[1001], b[1001];
    int i = 0, j = 0, k = 0, l = 0, cnt = 0, sizea = 0, sizeb = 0;

    scanf("%s", a);
    scanf("%s", b);
    
    while (a[sizea]!=0)
	sizea++;
    while (b[sizeb]!=0)
	sizeb++;
    for (i=0; i<sizeb; i++)
    {
	if (i+j==sizea)
	    break;
	else if (a[i+j]==b[i])
	{
	    if (i==sizeb-1)
	    {
		cnt++;
		j++;
		i = -1;
	
	    }
	}
	else
	{
	    j++;
	    i = -1;
	}
    }
    printf("%d\n", cnt);
    return 0;
}

#include <stdio.h>
#include <string.h>

int str_fnd(char *x, char *y, int *A, int len_x, int len_y)
{
    int i, j, check, cnt =0;


    for (j=0; j<len_x - len_y + 1; )
    {
	check = 0;
	for (i=0; i<len_y; i++)
	{
	    if (y[i] == '?')
		check++;
	    else if (x[j+i] == y[i])
		check++;
	    else
		break;
	}
	if (check==len_y)
	{
	    A[cnt]=j;
//	    printf("A[%d] = %d\n", cnt, A[cnt]);
	    cnt++;
	    j = j+ len_y;
	}
	else
	    j++;
    }
    return cnt;
}


int main()
{
    char x[1001], y[1001], z[1001];
    int A[1001];
    int i, j;
    int len_x = 0, len_y = 0;
    int cnt = 0;
    
    char ch;
    while ((ch=getchar()) != '\n')
    {
	x[len_x] = ch;
//	printf("x[%d] = %c\n", len_x, x[len_x]);
	len_x++;
    }
    x[len_x] = '\0';
    while ((ch=getchar()) != '\n')
    {
	y[len_y] = ch;
	len_y++;
    }
    i = 0;
    while ((ch=getchar()) != '\n')
    {
	z[i] = ch;
	i++;
    }

    cnt=str_fnd(x,y,A,len_x,len_y);
    
    for (i=0; i<cnt; i++)
    {
	for (j=0; j<len_y; j++)
	    x[A[i]+j] = z[j];
    }
    
    for (i=0; i<len_x; i++)
	printf("%c", x[i]);
   
    printf("%s\n", x);

    return 0;
}

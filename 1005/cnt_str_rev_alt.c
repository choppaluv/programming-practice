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

    for (i=0; i<sizea-sizeb+1; i++)
    {
        // check if 'b' matches for current pos
        for (j=0; j<sizeb; j++)
        {
            if (a[i+j] != b[j]) break;
        }
        if (j == sizeb) cnt++;  // matched
    }

    printf("%d\n", cnt);

    return 0;
}

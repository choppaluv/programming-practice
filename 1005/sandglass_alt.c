#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    
    scanf("%d",&n);

    for (i=-n+1; i<n; i++) {
        for (j=-n+1; j<n; j++) {
            if (abs(j) <= abs(i))
                putchar('*');
            else
                putchar(' ');
        }
        putchar('\n');
    }

    return 0;
}

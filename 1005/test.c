#include <stdio.h>

int main(){
    char a[1001], b[1001];
    int sizea = 0, sizeb =0;
    int i, j;

    scanf("%s",a);
    scanf("%s",b);

    while (a[sizea] != 0) sizea++;
    while (b[sizeb] != 0) sizeb++;

    for (i=0; i < sizea - sizeb +1 ; i++) 
    {
	for (j=0; j < sizeb; j++)
	{
	    if (a[i+j]!=b[j]) break;
	}
	if (j==sizeb) break;
    }
    if (i!=sizea-sizeb+1) printf("Yes\n");
    else printf("No\n");
    return 0;
}

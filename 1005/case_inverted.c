#include <stdio.h>

int main() 
{
    char input[1001], output[1001];
    int i = 0, j, k;

    scanf("%s", input);
    while (input[i]!=0) 
	i++;
    for (j=0; j<i; j++)
    {
	if (input[j]>='a' && input[j]<='z')
	{
	    output[j] = input[j] + 'A' -'a';
	    continue;
	}
	else if(input[j]>='A' && input[j]<='Z')
	{
	    output[j] = input[j] + 'a' -'A';
	    continue;
	}
    }
    for (k=0; k<i; k++)
    {
	printf("%c",output[k]);
    }
    return 0;
}

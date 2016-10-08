#include <stdio.h>

int main() 
{
    char input[1001], output[1001];
    int len = 0, j, k;	// len is more comprensive name than i since it will be used to store the length of input string

    scanf("%s", input);
    while (input[len]!=0) 
	len++;
    for (j=0; j<len; j++)
    {
	if (input[j]>='a' && input[j]<='z')
	{
	    output[j] = input[j] + 'A' -'a';
	    continue; // not necessary
	}
	else if (input[j]>='A' && input[j]<='Z')
	{
	    output[j] = input[j] + 'a' -'A';
	    continue; // not necessary
	}
    }
    for (k=0; k<len; k++)
    {
	printf("%c",output[k]);  // you can print a string with just one printf() call like printf("%s", string)
    }
    printf("\n");	// not a must, but missing newline in output makes me uncomfortable :-)
    return 0;
}

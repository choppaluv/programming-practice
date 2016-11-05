#include <stdio.h>

int main()
{
    int N;
    scanf("%d\n", &N);

    int i;
    char command[7];
    char word[1001];
    for (i=0; i<N; i++)
    {
	scanf("%s", command);
	printf("%s\n", command);
	scanf("%s\n", word);
	printf("%s\n", word);
    }
    return 0;
}

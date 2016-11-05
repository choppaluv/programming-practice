#include <stdio.h>
#include <stdlib.h>

int decimal_to_binary(int len, unsigned long long int z)
{
    int i;
    int binary[len];
    for (i=len-1; i>=0; i--)
    {
	binary[i] = z % 2;
	z = z / 2;
    }  
    for (i=0; i<len; i++)
	printf("%d", binary[i]);
    printf("\n");
}

int bitwise(unsigned long long int *answer, char *query, int x, int y, int len)
{
    unsigned long long int z;
    if (strcmp(query, "and")==0)
	z = answer[x] & answer[y];
    else if (strcmp(query, "or")==0)
	z = answer[x] | answer[y];
    else if (strcmp(query, "xor")==0)
	z = answer[x] ^ answer[y];
    else if (strcmp(query, "right")==0)
	z = answer[x] >> y;
    else if (strcmp(query, "left")==0)
	z = answer[x] << y;
    decimal_to_binary(len, z);
    return 0;
} 

int main()
{
    int i;
    int N, M;
    char *query;
    char tmp[6];

    query = tmp;

    int x, y;
    scanf("%d",&N);
    scanf("%d\n",&M);
    
    unsigned long long int answer[N];

    char c;
    int len;

    for (i=0; i<N; i++)
    {
	len=0;
	answer[i] = 0; 
	while ((c = getchar()) != '\n')
	{
	    answer[i] = answer[i] * 2;
	    answer[i] += c-48;
	    len++;
	}
//	printf("%d\n",answer[i]);
    }

//  printf("M = %d\n",M);
    for (i=0; i<M; i++)
    {
	scanf("%s", query);
//	printf("%s\n", query);
	scanf("%d", &x);
	scanf("%d", &y);
	bitwise(answer, query, x, y, len);
    }
    return 0;
}

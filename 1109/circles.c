#include <stdio.h>
#include <stdlib.h>

void intersect(int **circles, int num1, int num2)
{
    int dist = (circles[num1][0]-circles[num2][0])*(circles[num1][0]-circles[num2][0]) + (circles[num1][1]-circles[num2][1])*(circles[num1][1]-circles[num2][1]);
    int sum, dif;
    sum = (circles[num1][2] + circles[num2][2])*(circles[num1][2] + circles[num2][2]);
    dif = (circles[num1][2] - circles[num2][2]) * (circles[num1][2] - circles[num2][2]);

    if (dif<=dist && dist<=sum)
	printf("yes\n");
    else
	printf("no\n");
}

    
int main()
{
    int N, Q;
    scanf("%d %d",&N, &Q);
    int i;
    int **circles = (int **) malloc(sizeof(int *)*1500);
    for(i=0; i<1500; i++)
	circles[i] = (int *) malloc(sizeof(int)*3);

    for (i=0; i<N; i++)
	scanf("%d %d %d", &circles[i][0], &circles[i][1], &circles[i][2]);

    int num1, num2;
    for (i=0; i<Q; i++)
    {
	scanf("%d %d", &num1, &num2);
	intersect(circles, num1, num2);
    }
    return 0;
}

#include <stdio.h>
int main(){
	int  i=0, x ;
	double average = 0;
	while (scanf("%d",&x)!= EOF){
		i++;
		average = average + (double)(x - average)/i ;
	}
	printf("average = %.6f\n",average);
	return 0;
}

#include <stdio.h>
int main(){
	int input[1000],j, i=0;
	while(scanf("%d",&input[i])!=EOF){
		i++;
	}
	for(j=i-1; j>=0; j--){
		printf("%d ",input[j]);
	}
	printf("\n");
	return 0;
}

#include <stdio.h>
int main(){
	char input[1000];
	int j, i=0, output=1;
	while(scanf("%c",&input[i])!= EOF){
		i++;
	}
	for(j=0; j<i/2; j++){
		if(input[j]==input[i-j-1]){
			continue;
		}
		output=0;
		break;
	}
	if(output==1)
		printf("True\n");
	else
		printf("False\n");
	return 0;
}

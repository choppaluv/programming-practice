#include <stdio.h>
int main(){
	int x, max = -1, second_max;
	while (scanf("%d",&x)!=EOF){
		if(x>max){
			second_max = max;
			max = x;
		}
		else {
			if(x>second_max && x!=max){
				second_max = x;
		}
	}
	}
	printf("second max = %d\n",second_max);
	return 0;
}

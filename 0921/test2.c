#include <stdio.h>
int main(){
	int x, max = -1, second_max, third_max;
	while (scanf("%d",&x)!=EOF){
		if(x>max){
			third_max = second_max;
			second_max = max;
			max = x;
		}
		else {
			if(x>second_max && x!=max){
				third_max = second_max;
				second_max = x;
			}
			else{
				if(x>third_max && x!=second_max && x!=max){
					third_max = x;
				}
			}	
		}
	}
	printf("third max = %d\n",third_max);
	return 0;
}

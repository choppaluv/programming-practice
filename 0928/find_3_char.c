#include <stdio.h>
int main(){
	char msg[] = "C is a general-purpose, imperative computer programming language, supporting structured programming, lexical variable scope and recursion, while a static type system prevents many unintended operations.";
	char input[3];
	int j=0, i=0, n=0;
	for(j=0; j<3; j++){
		input[j] = getchar();
	}
	while(msg[i]!='\0'){
		if(msg[i]==input[0] && msg[i+1]==input[1] && msg[i+2]==input[2]){
			n++;
		}
		i++;
	}
	printf("%d\n",n);
	return 0;
}

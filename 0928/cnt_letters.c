#include <stdio.h>
int main(){
	char letters[26], x;
	int num[26], i, j, k=0;
	for(j=0; j<26; j++){
		letters[j] = 'a'+j;
		num[j] = 0;
	} 
	while (scanf("%c", &x)!=EOF){
		if(x >= 'a' && x <= 'z'){
			i = x - 'a';
			num[i] = num[i] + 1;
		}
		else if(x >= 'A' && x <= 'Z'){
			i = x - 'A';
			num[i] = num[i] + 1;
		     }	
	}
	while(k < 26){
		if(num[k]>0){
		printf("%c: %d ",letters[k],num[k]);
		}
		k++;
	} 
	return 0;
}


#include <stdio.h>
#include <string.h>

void main(int argc, char *argv[])
{
	FILE *in, *pat, *out;
	in = fopen(argv[1], "r");
	pat = fopen(argv[2], "r");
	out = fopen(argv[3], "w");
	char pattern[100];
	char change[100];
	char input[1001];
	fscanf(pat,"%s", pattern);
	fscanf(pat,"%s", change);
	fscanf(in,"%s", input);

	int i; 
	int len = strlen(pattern);
	for (i=0; i<strlen(input)-len; i++)
		if (strncmp(input+i, pattern,len)==0) 
		{
			strncpy(input+i, change,len);
			i = i+len-1;
		}
	fprintf(out, "%s", input);
	
	fclose(in);
	fclose(pat);
	fclose(out);
}

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char sentence[1000];
	FILE *fp;

	fp = fopen("My secret/secret.txt","w");
	if(fp == NULL)
	{
		printf("Error!");
		exit(1);
	}
	printf("Enter a sentence :\n");
	gets(sentence);
	fprintf(fp,"%s",sentence);
	fclose(fp);
	return 0;
}
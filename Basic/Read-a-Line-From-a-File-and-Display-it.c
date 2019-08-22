#include<stdio.h>
#include<stdlib.h>

int main()
{
	char c[1000];
	FILE *fp;

	if((fp = fopen("My secret/program.txt","r")) == NULL)
	{
		printf("Error! Opening file.");
		exit(1);
	}
	fscanf(fp,"%[^\n]",c);
	printf("Data from the file : \n%s",c);
	fclose(fp);
	return 0;
}
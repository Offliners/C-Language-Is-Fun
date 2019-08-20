#include<stdio.h>

int main()
{
	char string[1000];
	int i;

	printf("Enter a string : ");
	scanf("%s",string);
	for(i = 0;string[i] != '\0';i++);
	printf("Length of string : %d",i);
	return 0;
}
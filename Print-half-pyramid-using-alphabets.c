#include<stdio.h>

int main()
{
	char input,alphbet = 'A';

	printf("Enter the uppercase character you want to print in last row : ");
	scanf("%c",&input);
	for(int i = 1;i <= (input-'A'+1);i++)
	{
		for(int j = 1;j <= i;j++)
			printf("%c",alphbet);
		alphbet++;
		printf("\n");
	}	
	return 0;
}
#include<stdio.h>

int main()
{
	int row,number = 1;

	printf("Enter number of rows : ");
	scanf("%d",&row);
	for(int i = 1;i <= row;i++)
	{
		for(int j = 1;j <= i;j++)
		{
			printf("%d ",number);
			number++;
		}
		printf("\n");
	}
	return 0;
}
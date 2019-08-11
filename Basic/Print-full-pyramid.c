#include<stdio.h>

int main()
{
	int row,k = 0;

	printf("Enter number of rows : ");
	scanf("%d",&row);
	for(int i = 1;i <= row;i++,k = 0)
	{
		for(int space = 1;space <= row - i;space++)
			printf("  ");
		while(k != 2*i - 1)
		{
			printf("* ");
			k++;
		}
		printf("\n");
	}
	return 0;
}
#include<stdio.h>

int main()
{
	int row,k = 0,count = 0,count1 = 0;

	printf("Enter number of rows : ");
	scanf("%d",&row);
	for(int i = 1;i <= row;i++)
	{
		for(int space = 1;space <= row - i;space++)
		{
			printf("  ");
			count++;
		}
		while(k != 2*i - 1)
		{
			if(count <= row - 1)
			{
				printf("%d ",i+k);
				count++;
			}
			else
			{
				count1++;
				printf("%d ",(i + k - 2*count1));
			}
			k++;
		}
		count1 = count = k = 0;
		printf("\n");
	}
	return 0;
}
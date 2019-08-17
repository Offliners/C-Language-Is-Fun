#include<stdio.h>

int main()
{
	int row,column,a[100][100],b[100][100],sum[100][100];

	printf("Enter number of rows (between 1 and 100) : ");
	scanf("%d",&row);
	printf("Enter number of columns (between 1 and 100) : ");
	scanf("%d",&column);
	printf("Enter elements of 1st matrix :\n");
	for(int i = 0; i < row;i++)
	{
		for(int j = 0;j < column;j++)
		{
			printf("Enter element a%d%d : ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter elements of 2nd matrix :\n");
	for(int m = 0; m < row;m++)
	{
		for(int n = 0;n < column;n++)
		{
			printf("Enter element a%d%d : ",m+1,n+1);
			scanf("%d",&b[m][n]);
		}
	}
	for(int k = 0;k < row;k++)
	{
		for(int t = 0;t < column;t++)
			sum[k][t] = a[k][t] + b[k][t];
	}
	printf("Sum of two matrix is : \n");
	for(int x = 0;x < row;x++)
	{
		for(int y = 0;y < column;y++)
		{
			printf("%d  ",sum[x][y]);
			if(y == column - 1)
				printf("\n");
		}
	}
	return 0;
}

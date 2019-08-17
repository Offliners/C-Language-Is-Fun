#include<stdio.h>

int main()
{
	int row1,column1,row2,column2,a[10][10],b[10][10],result[10][10];

	printf("Enter row and column for 1st matrix : ");
	scanf("%d %d",&row1,&column1);
	printf("Enter row and column for 2nd matrix : ");
	scanf("%d %d",&row2,&column2);
	while(column1 != row2)
	{
		printf("Error! column of the first matrix not equal to row of the second.\n");
		printf("Enter row and column for 1st matrix : ");
		scanf("%d %d",&row1,&column1);
		printf("Enter row and column for 2nd matrix : ");
		scanf("%d %d",&row2,&column2);
	}
	printf("Enter elements of 1st matrix :\n");
	for(int i = 0; i < row1;i++)
	{
		for(int j = 0;j < column1;j++)
		{
			printf("Enter element a%d%d : ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter elements of 2st matrix :\n");
	for(int m = 0; m < row2;m++)
	{
		for(int n = 0;n < column2;n++)
		{
			printf("Enter element a%d%d : ",m+1,n+1);
			scanf("%d",&b[m][n]);
		}
	}
	for(int k = 0;k < row1;k++)
	{
		for(int t = 0;t < column2;t++)
			result[k][t] = 0;
	}
	for(int x = 0;x < row1;x++)
	{
		for(int y = 0;y < column2;y++)
		{
			for(int z = 0;z < column1;z++)
				result[x][y] += a[x][z] * b[z][y];
		}
	}
	printf("Output matrix is :\n");
	for(int q = 0;q < row1;q++)
	{
		for(int w = 0;w < column2;w++)
		{
			printf("%d  ",result[q][w]);
			if(w == column2 - 1)
				printf("\n");
		}
	}
	return 0;
}

#include<stdio.h>

int main()
{
	int a[10][10],transpose[10][10],row,column;

	printf("Enter row and column of matrix : ");
	scanf("%d %d",&row,&column);
	printf("Enter elements of matrix :\n");
	for(int i = 0;i < row;i++)
	{
		for(int j = 0;j < column;j++)
		{
			printf("Enter element a%d%d ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nEntered Matrix :\n");
	for(int m = 0;m < row;m++)
	{
		for(int n = 0;n < column;n++)
		{
			printf("%d  ",a[m][n]);
			if(n == column - 1)
				printf("\n");
		}
	}
	for(int x = 0;x < row;x++)
	{
		for(int y = 0;y < column;y++)
			transpose[y][x] = a[x][y];
	}
	printf("\nTranspose of Matrix :\n");
	for(int q = 0;q < column;q++)
	{
		for(int w = 0;w < row;w++)
		{
			printf("%d  ",transpose[q][w]);
			if(w == row - 1)
				printf("\n");
		}
	}
	return 0;
}
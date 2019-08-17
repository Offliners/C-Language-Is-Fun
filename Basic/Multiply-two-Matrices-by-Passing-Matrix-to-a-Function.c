#include<stdio.h>

void enterData(int array1[][10],int second[][10],int row1,int column1,int row2,int coulmn2);
void multiplyMatrix(int array1[][10],int second[][10],int result[][10],int row1,int column1,int row2,int coulmn2);
void Display(int result[][10],int row1,int column2);

int main()
{
	int array1[10][10],array2[10][10],result[10][10],row1,column1,row2,column2;

	printf("Enter row and column for 1st matrix : ");
	scanf("%d %d",&row1,&column1);
	printf("Enter row and column for 2nd matrix : ");
	scanf("%d %d",&row2,&column2);
	while(column1 != row2)
	{
		printf("Error! Column of the first matrix not equal to row of the second.\n");
		printf("Enter row and column for 1st matrix : ");
		scanf("%d %d",&row1,&column1);
		printf("Enter row and column for 2nd matrix : ");
		scanf("%d %d",&row2,&column2);
	}
	enterData(array1,array2,row1,column1,row2,column2);
	multiplyMatrix(array1,array2,result,row1,column1,row2,column2);
	Display(result,row1,column2);
	return 0;
}

void enterData(int array1[][10],int array2[][10],int row1,int column1,int row2,int column2)
{
	printf("Enter elements of 1st matrix :\n");
	for(int i = 0;i < row1;i++)
	{
		for(int j = 0;j < column1;j++)
		{
			printf("Enter elements a%d%d : ",i + 1,j + 1);
			scanf("%d",&array1[i][j]);
		}
	}
	printf("Enter elements of 2nd matrix :\n");
	for(int m = 0;m < row2;m++)
	{
		for(int n = 0;n < column2;n++)
		{
			printf("Enter elements b%d%d : ",m + 1,n + 1);
			scanf("%d",&array2[m][n]);
		}
	}
}

void multiplyMatrix(int array1[][10],int array2[][10],int result[][10],int row1,int column1,int row2,int column2)
{
	for(int q = 0;q < row1;q++)
	{
		for(int w = 0;w < column2;w++)
			result[q][w] = 0;
	}
	for(int x = 0;x < row1;x++)
	{
		for(int y = 0;y < column2;y++)
		{
			for(int z = 0;z < column1;z++)
				result[x][y] += array1[x][z] * array2[z][y];
		}
	}

}

void Display(int result[][10],int row1,int column2)
{
	printf("Output Matrix :\n");
	for(int k = 0;k < row1;k++)
	{
		for(int t = 0;t < column2;t++)
		{
			printf("%d  ",result[k][t]);
			if(t == column2 - 1)
				printf("\n");
		}
	}
}
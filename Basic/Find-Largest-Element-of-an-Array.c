#include<stdio.h>

int main()
{
	int num;
	float array[100],temp;

	printf("Enter total number of elements(1 - 100) : ");
	scanf("%d",&num);
	for(int i = 0;i < num;i++)
	{
		printf("Enter number %d : ",i+1);
		scanf("%f",&array[i]);
	}
	for(int j = 1;j < num;j++)
	{
		if(array[0] < array[j])
		{
			temp = array[0];
			array[0] = array[j];
			array[j] = temp;
		}
	}
	printf("Largest element = %.2f",array[0]);
	return 0;
}
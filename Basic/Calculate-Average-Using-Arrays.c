#include<stdio.h>

int main()
{
	int num;
	float array[100],sum = 0.0,avg;

	printf("Enter the numbers of elements : ");
	scanf("%d",&num);
	while(num > 100 || num <= 0)
	{
		printf("Error! Number should in range of 1 to 100.\n");
		printf("Enter the number again : ");
		scanf("%d",&num);
	}
	for(int i = 0;i < num;i++)
	{
		printf("%d. Enter number : ",i+1);
		scanf("%f",&array[i]);
		sum += array[i];
	}
	avg = sum / num;
	printf("Average = %.2f",avg);
	return 0;
}
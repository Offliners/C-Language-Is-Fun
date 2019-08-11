#include<stdio.h>

int checkPrimeNumber(int num);

int main()
{
	int num1,num2,flag;

	printf("Enter two positive integers : ");
	scanf("%d %d",&num1,&num2);
	printf("Prime numbers between %d and %d are : ",num1,num2);
	for(int i = num1 + 1;i < num2;i++)
	{
		flag = checkPrimeNumber(i);
		if(flag == 1)
			printf("%d ",i);
	}
	return 0;
}

int checkPrimeNumber(int num)
{
	int flag = 1;
	for(int j = 2;j <= num/2;j++)
	{
		if(num % j == 0)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}
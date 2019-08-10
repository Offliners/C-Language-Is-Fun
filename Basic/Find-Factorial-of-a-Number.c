#include<stdio.h>

int main()
{
	int num;
	unsigned long long factorial = 1;

	printf("Enter an integer : ");
	scanf("%d",&num);
	if(num < 0)
		printf("Error! Factorial of a negative number doesn't exist.");
	else
	{
		for(int i = 1;i <= num;i++)
			factorial *= i;
		printf("%d! = %llu",num,factorial);
	}
	return 0;
}
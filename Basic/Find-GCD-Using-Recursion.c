#include<stdio.h>

int GCD(int num1,int num2);

int main()
{
	int num1,num2;

	printf("Enter two positive integers : ");
	scanf("%d %d",&num1,&num2);
	printf("Greatest Common Divisor of %d and %d is %d",num1,num2,GCD(num1,num2));
	return 0;
}

int GCD(int num1,int num2)
{
	if(num2 != 0)
		return GCD(num2,num1 % num2);
	else
		return num1;
}
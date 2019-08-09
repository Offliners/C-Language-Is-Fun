#include<stdio.h>

int main()
{
	double num1,num2,temp;

	printf("Enter the first number : ");
	scanf("%lf",&num1);
	printf("Enter the second number : ");
	scanf("%lf",&num2);

	temp = num1;
	num1 = num2;
	num2 = temp;

	printf("\nAfter swapping, num1 = %.2lf",num1);
	printf("\nAfter swapping, num2 = %.2lf",num2);
	return 0;
}
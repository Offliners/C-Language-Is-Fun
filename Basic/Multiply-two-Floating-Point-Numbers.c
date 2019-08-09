#include<stdio.h>

int main()
{
	double num1,num2,product;
	printf("Enter two numbers : ");
	scanf("%lf %lf",&num1,&num2);
	product = num1 * num2;
	printf("Product = %.2lf",product);
	return 0;
}
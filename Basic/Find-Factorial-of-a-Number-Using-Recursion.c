#include<stdio.h>

long int multiplyNumber(int num);

int main()
{
	int num;

	printf("Enter a positive integer : ");
	scanf("%d",&num);
	printf("%d!  = %d",num,multiplyNumber(num));
	return 0;
}

long int multiplyNumber(int num)
{
	if(num >= 1)
		return num * multiplyNumber(num - 1);
	else
		return 1;
}
#include<stdio.h>

int addNumber(int num);

int main()
{
	int num;

	printf("Enter a positive number : ");
	scanf("%d",&num);
	printf("Sum = %d",addNumber(num));
	return 0;
}

int addNumber(int num)
{
	if(num != 0)
		return num + addNumber(num - 1);
	else
		return num;
}
#include<stdio.h>

int main()
{
	int num,rev = 0,remainder,origin;

	printf("Enter an integer : ");
	scanf("%d",&num);
	origin = num;
	while(num != 0)
	{
		remainder = num % 10;
		rev = rev * 10 + remainder;
		num /= 10;
	}
	if(origin == rev)
		printf("%d is a palindrome.",origin);
	else
		printf("%d is not a palindrome.",origin);
	return 0;
}
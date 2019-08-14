#include<stdio.h>

int power(int base,int exp);

int main()
{
	int base,exp,result;

	printf("Enter base number : ");
	scanf("%d",&base);
	printf("Enter power number (positive integer) : ");
	scanf("%d",&exp);
	result = power(base,exp);
	printf("%d ^ %d = %d",base,exp,result);
	return 0;
}

int power(int base,int exp)
{
	if(exp != 0)
		return base * power(base,exp - 1);
	else
		return 1;
}
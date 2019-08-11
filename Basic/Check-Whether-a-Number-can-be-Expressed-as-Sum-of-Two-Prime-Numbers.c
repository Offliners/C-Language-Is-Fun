#include<stdio.h>

int checkPrime(int num);

int main()
{
	int num,flag = 0;

	printf("Enter a positive integer : ");
	scanf("%d",&num);
	for(int i = 2;i <= num/2;i++)
	{
		if(checkPrime(i) == 1)
		{
			if(checkPrime(num - i) == 1)
			{
				printf("%d  = %d + %d\n",num,i,num - i);
				flag = 1;
			}
		}
	}
	if(flag == 0)
		printf("%d can't be expressed as the sum of two prime numbers.",num);
	return 0;
}

int checkPrime(int num)
{
	int isPrime = 1;
	for(int i = 2;i <= num/2;i++)
	{
		if(num % i == 0)
		{
			isPrime = 0;
			break;
		}
	}
	return isPrime;
}
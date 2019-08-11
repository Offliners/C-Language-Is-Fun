#include<stdio.h>
#include<math.h>

int checkPrimeNumber(int num);
int checkArmstrongNumber(int num);

int main()
{
	int num,flag;

	printf("Enter a positive number : ");
	scanf("%d",&num);
	flag = checkPrimeNumber(num);
	if(flag == 1)
		printf("%d is a prime number.\n",num);
	else
		printf("%d is not a prime number.\n",num);
	flag = checkArmstrongNumber(num);
	if(flag == 1)
		printf("%d is an Armstrong number.\n",num);
	else
		printf("%d is not an Armstrong number.\n",num);
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

int checkArmstrongNumber(int num)
{
	int origin,remainder,result = 0,n = 0,flag;
	origin = num;
	while(origin != 0)
	{
		origin /= 10;
		n++;
	}
	origin = num;
	while(origin != 0)
	{
		remainder = origin % 10;
		result += pow(remainder,n);
		origin /= 10;
	}
	if(result == num)
		flag = 1;
	else
		flag = 0;
	return flag;
}
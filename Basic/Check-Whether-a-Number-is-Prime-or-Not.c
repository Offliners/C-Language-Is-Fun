#include<stdio.h>

int main()
{
	int num,flag = 0;

	printf("Enter a positive integer : ");
	scanf("%d",&num);
	for(int i = 2;i <= num/2;i++)
	{
		if(num % i == 0)
		{
			flag = 1;
			break;
		}
	}
	if(num == 1)
		printf("1 is neither a prime or a composite number.");
	else
	{
		if(flag == 0)
			printf("%d is a prime number.",num);
		else
			printf("%d is a composite number.",num);	
	}
	return 0;
}
#include<stdio.h>

int main()
{
	int num1,num2,gcd,lcm;

	printf("Enter two integers : ");
	scanf("%d %d",&num1,&num2);
	for(int i = 1;i <= num1 && i <= num2;i++)
	{
		if(num1 % i == 0 && num2 % i == 0)
			gcd = i;
	}
	lcm = (num1 * num2)/gcd;
	printf("Greatest Common Divisor of %d and %d is %d\n",num1,num2,gcd);
	printf("Least Common Multiple of %d and %d is %d\n",num1,num2,lcm);
	return 0; 
}
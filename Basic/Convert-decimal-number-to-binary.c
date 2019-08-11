#include<stdio.h>
#include<math.h>

long long convertDecimalToBinary(int num);

int main()
{
	int num;

	printf("Enter a decimal number : ");
	scanf("%d",&num);
	printf("%d in decimal = %lld in binary",num,convertDecimalToBinary(num));
	return 0;
}

long long convertDecimalToBinary(int num)
{
	long long binaryNumber = 0;
	int remainder,i = 1,step = 1;

	while(num != 0)
	{
		remainder = num % 2;
		printf("Step %d : %d / 2,remainder = %d,Quotient = %d\n",step++,num,remainder,num/2);
		num /= 2;
		binaryNumber += remainder * i;
		i *= 10;
	}
	return binaryNumber;
}
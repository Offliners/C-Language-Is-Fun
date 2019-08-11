#include<stdio.h>
#include<math.h>

int convertBinaryToDecimal(long long num);

int main()
{
	long long num;

	printf("Enter a binary number : ");
	scanf("%lld",&num);
	printf("%lld in binary = %d in decimal",num,convertBinaryToDecimal(num));
	return 0;
}

int convertBinaryToDecimal(long long num)
{
	int decimalNumber = 0,i = 0,remainder;

	while(num != 0)
	{
		remainder = num % 10;
		num /= 10;
		decimalNumber += remainder * pow(2,i);
		i++;
	}
	return decimalNumber;
}
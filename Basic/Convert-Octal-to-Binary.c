#include<stdio.h>
#include<math.h>

long long convertOctalToBinary(int octal);

int main()
{
	int octal;

	printf("Enter a octal number : ");
	scanf("%d",&octal);
	printf("%d in octal = %lld in binary",octal,convertOctalToBinary(octal));
	return 0;
}

long long convertOctalToBinary(int octal)
{
	long long binary = 0;
	int decimal = 0,i = 0;

	while(octal !=0)
	{
		decimal += (octal % 10) * pow(8,i);
		i++;
		octal /= 10;
	}
	i = 1;
	while(decimal != 0)
	{
		binary += (decimal % 2) * i;
		decimal /= 2;
		i *= 10;
	}
	return binary;
}
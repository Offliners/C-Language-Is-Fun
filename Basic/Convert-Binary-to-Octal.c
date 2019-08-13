#include<stdio.h>
#include<math.h>

int convertBinaryToOctal(long long binary);

int main()
{
	long long binary;

	printf("Enter a binary number : ");
	scanf("%lld",&binary);
	printf("%lld in binary = %d in octal",binary,convertBinaryToOctal(binary));
	return 0;
}

int convertBinaryToOctal(long long binary)
{
	int octal = 0,decimal = 0,i = 0;

	while(binary !=0)
	{
		decimal += (binary % 2) * pow(2,i);
		i++;
		binary /= 10;
	}
	i = 1;
	while(decimal != 0)
	{
		octal += (decimal % 8) * i;
		decimal /= 8;
		i *= 10;
	}
	return octal;
}

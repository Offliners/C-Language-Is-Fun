#include<stdio.h>

int convertDecimalToOctal(int num);

int main()
{
	int num;

	printf("Enter a decial number : ");
	scanf("%d",&num);
	printf("%d in decimal = %d in octal",num,convertDecimalToOctal(num));
	return 0;
}

int convertDecimalToOctal(int num)
{
	int octal = 0,i = 1;

	while(num != 0)
	{
		octal += (num % 8) * i;
		num /= 8;
		i *= 10;
	}
	return octal;
}

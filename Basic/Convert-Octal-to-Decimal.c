#include<stdio.h>
#include<math.h>

long long convertOctaloDecimal(int octal);

int main()
{
	int octal;

	printf("Enter a octal number : ");
	scanf("%d",&octal);
	printf("%d in octal = %d in decimal",octal,convertOctaloDecimal(octal));
	return 0;
}

long long convertOctaloDecimal(int octal)
{
	int num = 0,i = 0;

	while(octal != 0)
	{
		num += (octal % 10) * pow(8,i);
		i++;
		octal /= 10;
	}
	return num;
}
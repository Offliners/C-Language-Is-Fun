#include<stdio.h>

struct Complex
{
	float real;
	float imag;
};

typedef struct Complex complex;

complex add(complex num1,complex num2);

int main()
{
	complex num1,num2,temp;

	printf("For 1st complex number\n");
	printf("Enter real and imaginary part respectively : ");
	scanf("%f %f",&num1.real,&num1.imag);
	printf("For 2nd complex number\n");
	printf("Enter real and imaginary part respectively : ");
	scanf("%f %f",&num2.real,&num2.imag);
	temp = add(num1,num2);
	printf("Sum = %.1f + %.1fi",temp.real,temp.imag);
	return 0;
}

complex add(complex num1,complex num2)
{
	complex temp;

	temp.real = num1.real + num2.real;
	temp.imag = num1.imag + num2.imag;
	return temp;
}

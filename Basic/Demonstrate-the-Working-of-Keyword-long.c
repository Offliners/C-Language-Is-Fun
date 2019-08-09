#include<stdio.h>

int main()
{
	int a;
	long b;
	long long c;
	double d;
	long double e;

	printf("Size of int = %ld bytes\n",sizeof(a));
	printf("Size of long = %ld bytes\n",sizeof(b));
	printf("Size of long long = %ld bytes\n",sizeof(c));
	printf("Size of double = %ld bytes\n",sizeof(d));
	printf("Size of long double = %ld bytes\n",sizeof(e));
	return 0;
}
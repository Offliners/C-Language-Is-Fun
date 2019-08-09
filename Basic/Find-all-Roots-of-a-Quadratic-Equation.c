#include<stdio.h>
#include<math.h>

int main()
{
	double a,b,c,d;
	double x1,x2,R,I;

	printf("Enter coefficients a , b and c : ");
	scanf("%lf %lf %lf",&a,&b,&c);
	d = b*b - 4*a*c;
	if(d > 0)
	{
		x1 = (-b+sqrt(d))/(2*a);
		x2 = (-b-sqrt(d))/(2*a);
		printf("Root 1 = %.2lf and Root 2 = %.2lf",x1,x2);
	}
	else if(d == 0)
	{
		x1 = x2 = -b/(2*a);
		printf("Root 1 = Root 2 = %.2lf",x1);
	}
	else
	{
		R = -b/(2*a);
		I = sqrt(-d)/(2*a);
		printf("Root 1 = %.2lf + %.2lfi and Root 2 = %.2lf - %.2lfi",R,I,R,I);
	}
	return 0;
}
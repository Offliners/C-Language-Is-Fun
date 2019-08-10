#include<stdio.h>
#include<math.h>

int main()
{
	int num,origin,remainder,result = 0,n = 0;

	printf("Enter an integer : ");
	scanf("%d",&num);
	origin = num;
	while(origin != 0)
	{
		origin /= 10;
		n++;
	}
	origin = num;
	while(origin != 0)
	{
		remainder = origin % 10;
		result += pow(remainder,n);
		origin /= 10;
	}
	if(result == num)
		printf("%d is an Armsrong number.",num);
	else
		printf("%d is not an Armsrong number.",num);
	return 0;	
}
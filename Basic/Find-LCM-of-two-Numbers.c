#include<stdio.h>

int main()
{
	int num1,num2,minMul;

	printf("Enter two positive integers : ");
	scanf("%d %d",&num1,&num2);
	minMul = (num1 > num2)? num1 : num2;
	while(1)
	{
		if(minMul % num1 == 0 && minMul % num2 == 0)
		{
			printf("Least Common Multiple of %d and %d is %d",num1,num2,minMul);
			break;
		}
		minMul++;
	}
	return 0;
}
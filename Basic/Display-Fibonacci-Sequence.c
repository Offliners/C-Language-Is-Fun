#include<stdio.h>

int main()
{
	int num,t1 = 0,t2 = 1,nextTern;

	printf("Enter the number of terns : ");
	scanf("%d",&num);
	printf("Fibonacci Series : ");
	for(int i = 1;i <= num; i++)
	{
		printf("%d, ",t1);
		nextTern = t1 + t2;
		t1 = t2;
		t2 = nextTern;
	}
	return 0;
}

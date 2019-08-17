#include<stdio.h>

int main()
{
	int data[5];

	printf("Enter elements : ");
	for(int i = 0;i < 5;i++)
		scanf("%d",data + i);
	printf("You entered :\n");
	for(int j = 0;j < 5;j++)
		printf("%d\n",*(data + j));
	return 0;
}
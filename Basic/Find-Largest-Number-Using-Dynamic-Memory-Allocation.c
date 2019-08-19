#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num;
	float *data;

	printf("Enter total number of elements (1 - 100) : ");
	scanf("%d",&num);
	data = (float*)calloc(num,sizeof(float));
	if(data == NULL)
	{
		printf("Error! Memory not allocated.");
		exit(0);
	}
	for(int i = 0;i < num;i++)
	{
		printf("Enter number %d : ",i+1);
		scanf("%f",data + i);
	}
	for(int j = 1;j < num;j++)
	{
		if(*data < *(data + j))
			*data = *(data + j);
	}
	printf("Largest element = %.2f",*data);
	return 0;
}
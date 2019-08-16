#include<stdio.h>
#include<math.h>

float calculateSD(float data[]);

int main()
{
	float data[10];

	printf("Enter 10 elements : ");
	for(int i = 0;i < 10;i++)
		scanf("%f",&data[i]);
	printf("Standard Deviation = %.6f",calculateSD(data));
	return 0;
}

float calculateSD(float data[])
{
	float sum = 0.0,mean,std = 0.0;
	for(int j = 0;j < 10;j++)
		sum += data[j];
	mean = sum / 10;
	for(int k = 0;k < 10;k++)
		std += pow(data[k] - mean,2);
	return sqrt(std/10);
}
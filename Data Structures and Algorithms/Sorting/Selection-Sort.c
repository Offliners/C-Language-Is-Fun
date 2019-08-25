#include<stdio.h>

void swap(int *a,int *b);
void selectionSort(int array[],int size);
void printArray(int array[],int size);

int main()
{
	int data[] = {20,12,10,15,2};
	int size = sizeof(data) / sizeof(data[0]);

	selectionSort(data,size);
	printf("Sorted array in ascending order :\n");
	printArray(data,size);
	return 0;
}

void swap(int *a,int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int array[],int size)
{
	int min;

	for(int step = 0; step < size- 1;step++)
	{
		min = step;

		for(int i = step + 1;i < size;i++)
		{
			if(array[i] < array[min])
				min = i;
		}
		swap(&array[min],&array[step]);
	}
}

void printArray(int array[],int size)
{
	for(int i = 0;i < size;i++)
		printf("%d ",array[i]);
	printf("\n");
}
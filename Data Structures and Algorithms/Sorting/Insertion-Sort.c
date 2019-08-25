#include<stdio.h>

void insertionSort(int array[],int size);
void printArray(int array[],int size);

int main()
{
	int data[] = {9,5,1,4,3};
	int size = sizeof(data) / sizeof(data[0]);

	insertionSort(data,size);
	printf("Sorted array in ascending order :\n");
	printArray(data,size);
}

void insertionSort(int array[],int size)
{
	int key,j;

	for(int step = 1;step < size;step++)
	{
		key = array[step];
		j = step - 1;
		for(;(key < array[j] && j >= 0);j--)
			array[j+1] = array[j];
		array[j+1] = key;
	}
}

void printArray(int array[],int size)
{
	for(int i = 0;i < size;i++)
		printf("%d ",array[i]);
	printf("\n");
}

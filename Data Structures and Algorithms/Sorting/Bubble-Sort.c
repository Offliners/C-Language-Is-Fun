#include<stdio.h>

void bubbleSort(int array[],int size);
void printArray(int array[],int size);

int main()
{
	int data[] = {-2,45,0,11,-9};
	int size = sizeof(data) / sizeof(data[0]);

	bubbleSort(data,size);
	printf("Sorted array in ascending order :\n");
	printArray(data,size);
	return 0;
}

void bubbleSort(int array[],int size)
{
	for(int pass = 0;pass < size - 1;pass++)
	{
		for(int i = 0;i <size - pass - 1;i++)
		{
			if(array[i] > array[i+1])
			{
				int temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
			}
		}
	}
}

void printArray(int array[],int size)
{
	for(int i = 0;i < size;i++)
		printf("%d ",array[i]);
	printf("\n");
}
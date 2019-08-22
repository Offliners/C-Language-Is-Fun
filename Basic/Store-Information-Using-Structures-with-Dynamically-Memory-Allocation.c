#include<stdio.h>
#include<stdlib.h>

struct Course
{
	int mark;
	char subject[30];
};

typedef struct Course c;

int main()
{
	c *ptr;
	int records;

	printf("Enter number of records : ");
	scanf("%d",&records);
	ptr = (c*)malloc(records * sizeof(c));
	for(int i = 0;i < records;i++)
	{
		printf("Enter name of the subject and marks respectively :\n");
		scanf("%s %d",&(ptr+i)->subject,&(ptr+i)->mark);
	}
	printf("Displaying Information :\n");
	for(int j = 0;j < records;j++)
		printf("%s\t%d\n",(ptr+j)->subject,(ptr+j)->mark);
	return 0;
}
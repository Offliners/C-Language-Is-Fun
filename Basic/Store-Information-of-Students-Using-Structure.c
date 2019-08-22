#include<stdio.h>

struct Student
{
	char name[50];
	int roll;
	float mark;
}s[10];

int main()
{
	printf("Enter information of students :\n");
	for(int i = 0;i < 10;i++)
	{
		s[i].roll = i + 1;
		printf("For roll number %d,\n",s[i].roll);
		printf("Enter name : ");
		scanf("%s",s[i].name);
		printf("Enter marks : ");
		scanf("%f",&s[i].mark);
		printf("\n");
	}
	printf("Displaying information :\n");
	for(int j = 0;j < 10;j++)
	{
		printf("Roll number : %d\n",j+1);
		printf("Name : ");
		puts(s[j].name);
		printf("Marks : %.1f",s[j].mark);
		printf("\n");
	}
	return 0;
}
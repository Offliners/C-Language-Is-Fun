#include<stdio.h>

struct student
{
	char name[50];
	int roll;
	float marks;
} s;


int main()
{
	printf("Enter the student's information :\n");
	printf("Enter name : ");
	scanf("%s",s.name);
	printf("Enter roll number : ");
	scanf("%d",&s.roll);
	printf("Enter marks : ");
	scanf("%f",&s.marks);
	printf("\nDisplay information :\n");
	printf("Name : %s\n",s.name);
	printf("Roll number : %d\n",s.roll);
	printf("Marks : %.1f\n",s.marks);
	return 0;
}
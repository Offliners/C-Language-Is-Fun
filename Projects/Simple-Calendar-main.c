#include<stdio.h>
#include"Simple-Calendar-func.h"

int main()
{
	int year,month;

	printf("Enter year in A.D. (e.g. 2019) : ");
	scanf("%d",&year);
	printf("Enter month in number between 1-12 : ");
	scanf("%d",&month);
	printMonth(year,month);
	return 0;
}

#include<stdio.h>
#include"Simple-Calendar-func.h"

void printMonth(int year,int month)
{
	printMonthTitle(year,month);
	printMonthBody(year,month);
}

void printMonthTitle(int year,int month)
{
	printMonthName(month);
	printf(" %d\n",year);
	printf("------------------------------------------\n");
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
}

void printMonthName(int month)
{
	printf("             ");
	switch(month)
	{
		case 1:
			printf("January");
			break;
		case 2:
			printf("February");
			break;
		case 3:
			printf("March");
			break;
		case 4:
			printf("April");
			break;
		case 5:
			printf("May");
			break;
		case 6:
			printf("June");
			break;
		case 7:
			printf("July");
			break;
		case 8:
			printf("August");
			break;
		case 9:
			printf("September");
			break;
		case 10:
			printf("October");
			break;		
		case 11:
			printf("November");
			break;		
		case 12:
			printf("December");
			break;
		default:
			printf("Error!");
			break;
	}
}

void printMonthBody(int year,int month)
{
	int start = getStartDay(year,month);
	int amount = getDaysInMonth(year,month);

	for(int i = 0;i < start;i++)
		printf("     ");
	for(int j = 1;j <= amount;j++)
	{
		printf("%5d",j);
		if((j + start) % 7 == 0)
			printf("\n");
	}
}

int getStartDay(int year,int month)
{
	int start1800 = 3;
	int total = getTotalDaysInMonth(year,month);

	return ((total + start1800) % 7);
}

int getTotalDaysInMonth(int year,int month)
{
	int totalDays = 0;

	for(int i = 1800;i <= year - 1;i++)
	{
		if(isLeapYear(i))
			totalDays += 366;
		else
			totalDays += 365;
	}
	for(int j = 1;j <= month - 1;j++)
		totalDays += getDaysInMonth(year,j);
	return totalDays;
}

int getDaysInMonth(int year,int month)
{
	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	else if(month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	if(month == 2)
		return isLeapYear(year)? 29:28;
	return 0;
}

_Bool isLeapYear(int year)
{
	int flag;
	if(year % 4 == 0)
	{
		if(year % 100 == 0)
		{
			if (year % 400 == 0)
				flag = 1;
			else
			 	flag = 0;
		}
		else
			flag = 1;
	}
	else
		flag = 0;
	if(flag == 1)
		return 1;
	else
		return 0;
}

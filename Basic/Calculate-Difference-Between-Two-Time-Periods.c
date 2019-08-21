#include<stdio.h>

struct Time
{
	int second;
	int minute;
	int hour;
};

typedef struct Time t;

void diffTimePeriod(t t1,t t2,t *diff);

int main()
{
	t startTime,stopTime,diff;

	printf("Enter start time :\n");
	printf("Enter hours, minutes and seconds respectively : ");
	scanf("%d %d %d",&startTime.hour,&startTime.minute,&startTime.second);
	printf("Enter stop time :\n");
	printf("Enter hours, minutes and seconds respectively : ");
	scanf("%d %d %d",&stopTime.hour,&stopTime.minute,&stopTime.second);
	diffTimePeriod(startTime,stopTime,&diff);
	printf("Time difference : %d:%d:%d - ",startTime.hour,startTime.minute,startTime.second);
	printf("%d:%d:%d",stopTime.hour,stopTime.minute,stopTime.second);
	printf("= %d:%d:%d",diff.hour,diff.minute,diff.second);
	return 0;
}

void diffTimePeriod(t t1,t t2,t *diff)
{
	if(t2.second > t1.second)
	{
		t1.minute--;
		t1.second += 60;
	}
	diff->second = t1.second - t2.second;
	if(t2.minute > t1.minute)
	{
		t1.hour--;
		t1.minute += 60;
	}
	diff->minute = t1.minute - t2.minute;
	diff->hour = t1.hour - t2.hour;	
}
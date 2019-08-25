#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MAX 10

typedef struct stack
{
	int item[MAX];
	int top;
} st;

void createEmptyStack(st *s);
int isFull(st *s);
int isEmpty(st *s);
void push(st *s);
void pop(st *s);

int main()
{
	int option;
	int loop = 1;
	st *s;

	createEmptyStack(s);
	do
	{
		printf("======Stack Operations======\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Exit\n");
		printf("============================\n");
		printf("Enter your option : ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				push(s);
				break;
			case 2:
				pop(s);
				break;
			case 3:
				printf("Exit!");
				loop = 0;
				exit(0);
			default:
				printf("Invalid option!");
		}
	}while(loop);
	getch();
	return 0;
}

void createEmptyStack(st *s)
{
	s->top = -1;
}

int isFull(st *s)
{
	if(s->top == MAX - 1)
		return 1;
	else 
		return 0;
}

int isEmpty(st *s)
{
	if(s->top == -1)
		return 1;
	else
		return 0;
}

void push(st *s)
{
	int new;

	printf("Enter item to be inserted : ");
	scanf("%d",&new);
	if(isFull(s))
		printf("Stack full!\n");
	else
	{
		s->top++;
		s->item[s->top] = new;
	}
}

void pop(st *s)
{
	if(isEmpty(s))
		printf("Stack empty!\n");
	else
	{
		printf("Item popped = %d\n",s->item[s->top]);
		s->top--;
	}
}

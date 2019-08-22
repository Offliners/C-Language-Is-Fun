#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include"tic-tac-toe-func.h"

int board[10] = {2,2,2,2,2,2,2,2,2,2};
int turn = 1,flag = 0;
int player,computer;
COORD coord = {0,0};

void mainMenu()
{
	int select;
	system("cls");

	printf("----------Main Menu----------\n");
	printf("1. Play with X\n");
	printf("2. Play with O\n");
	printf("3. Exit game\n");
	printf("-----------------------------\n");
	printf("Enter your option : ");
	scanf("%d",&select);
	turn = 1;
	switch(select)
	{
		case 1:
			player = 1;
			computer = 0;
			playerFitst();
			break;
		case 2:
			player = 0;
			computer = 1;
			startGame();
			break;
		case 3:
			exit(1);
		default:
			mainMenu();
	}
}

void playerFitst()
{
	int pos;

	checkDraw();
	drawBoard();
	coordination(30,18);
	printf("Your turn : ");
	scanf("%d",&pos);
	if(board[pos] != 2)
		playerFitst();
	if(pos == possibleWin(player))
	{
		computerMove(pos);
		drawBoard();
		coordination(30,20);
		printf("Player Wins!");
		getch();
		exit(0);
	}
	computerMove(pos);
	drawBoard();
	startGame();
}

void startGame()
{
	if(possibleWin(computer))
	{
		computerMove(possibleWin(computer));
		flag = 1;
	}
	else if(possibleWin(player))
		computerMove(possibleWin(player));
	else if(make2())
		computerMove(make2());
	else
		computerMove(make4());
	drawBoard();
	if(flag)
	{
		coordination(30,20);
		printf("Computer Wins!");
		getch();
	}
	else
		playerFitst();
}

void coordination(int x,int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void drawBoard()
{
	for(int i = 9;i < 17;i++)
	{
		coordination(35,i);
		printf("|       |");
	}
	coordination(28,11);
	printf("-----------------------");
	coordination(28,14);
	printf("-----------------------");
	for(int j = 1;j < 10;j++)
	{
		if(board[j] == 3)
			putXandO('X',j);
		else if(board[j] == 5)
			putXandO('O',j);
	}
}

void putXandO(char ch,int pos)
{
	int loc = pos;
	int x = 31,y = 10;

	if(loc > 3)
	{
		while(loc > 3)
		{
			y += 3;
			loc -= 3;
		}
	}
	if(pos % 3 == 0)
		x += 16;
	else
	{
		pos %= 3;
		pos--;
		while(pos)
		{
			x += 8;
			pos--;
		}
	}
	coordination(x,y);
	printf("%c",ch);
}

int possibleWin(int p)
{
	int i = 1;
	int check,pos;

	if(p == 1)
		check = 18;
	else
		check = 50;
	while(i <= 9)
	{
		if(board[i] * board[i+1] * board[i+2] == check)
		{
			if(board[i] == 2)
				return i;
			if(board[i+1] == 2)
				return i + 1;
			if(board[i+2] == 2)
				return i + 2;
		}
		i += 3;
	}
	i = 1;
	while(i <= 3)
	{
		if(board[i] * board[i+3] * board[i+6] == check)
		{
			if(board[i] == 2)
				return i;
			if(board[i+3] == 2)
				return i + 3;
			if(board[i+6] == 2)
				return i + 6;
		}
		i++;
	}
	if(board[1] * board[5] * board[9] == check)
	{
		if(board[1] == 2)
			return 1;
		if(board[5] == 2)
			return 5;
		if(board[9] == 2)
			return 9;
	}
	if(board[3] * board[5] * board[7] == check)
	{
		if(board[3] == 2)
			return 3;
		if(board[5] == 2)
			return 5;
		if(board[7] == 2)
			return 7;
	}
	return 0;
}

void computerMove(int n)
{
	if(turn % 2)
		board[n] = 3;
	else
		board[n] = 5;
	turn++;
}

int make2()
{
	if(board[5] == 2)
		return 5;
	if(board[2] == 2)
		return 2;
	if(board[4] == 2)
		return 4;
	if(board[6] == 2)
		return 6;
	if(board[8] == 2)
		return 8;
	return 0;
}

int make4()
{
	if(board[1] == 2)
		return 1;
	if(board[3] == 2)
		return 3;
	if(board[7] == 2)
		return 7;
	if(board[9] == 2)
		return 9;
	return 0;
}

void checkDraw()
{
	if(turn > 9)
	{
		coordination(30,20);
		printf("Game Draw!");
		getch();
		exit(0);
	}
}
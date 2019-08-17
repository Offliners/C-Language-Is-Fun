#include<stdio.h>
#include<stdlib.h>
#include"Material-File-Management-func.h"

int main()
{
	int select;

	while(1)
	{
		mainMenu();
		scanf("%d",&select);
		if(select == 0)
			break;
		switch(select)
		{
			case 1:
				openFileandShowData();
				break;
			case 2:
				dataOperation();
				break;
			case 3:
				sortOperation();
				break;
			case 4:
				writeFile();
				break;
			case 5:
				system("cls");
				break;
			default:
				break;
		}
	}
	return 0;
}
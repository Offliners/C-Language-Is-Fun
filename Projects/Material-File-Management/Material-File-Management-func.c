#include<stdio.h>
#include<string.h>
#include"Material-File-Management-func.h"

char objType[NUM_OF_OBJECT_TYPE + 1][20] = {"Unknown","Ball","Cube","Pyramid","Cylinder"};
char materialType[NUM_OF_MATERIAL_TYPE + 1][20] = {"Unknown","Iron","Aluminum","Lead"};
char errorType[NUM_OF_ERROR_TYPE + 1][20] = {"Normal","Err_Object","Err_Material","Err_Para1","Err_Para2"};
double density[NUM_OF_MATERIAL_TYPE + 1] = {0,7.87,2.7,11.3};
char filePath[6][128] = {"WrongPath",FILE_TXT1,FILE_TXT2,FILE_TXT3,FILE_TXT4,FILE_TXT5};
objdata data[MAXSIZE];
int size = 0;

void mainMenu()
{
	printf("==========Main Menu==========\n");
	printf("0. Exit\n");
	printf("1. Open file and show data\n");
	printf("2. Data operation\n");
	printf("3. Sort operation\n");
	printf("4. Save data to file\n");
	printf("5. Clear screen\n");
	printf("==============================\n");
	printf("Please select an option :\n");
}

void operationMenu()
{
	printf("======File Operation Menu=====\n");
	printf("0. Main menu\n");
	printf("1. Print data\n");
	printf("2. Append data\n");
	printf("3. Update data\n");
	printf("4. Delete data\n");
	printf("==============================\n");
	printf("Please select an option :\n");
}

void sortMenu()
{
	printf("======Sort Operation Menu=====\n");
	printf("0. Main menu\n");
	printf("1. Sort by ID\n");
	printf("2. Sort by object type\n");
	printf("3. Sort by material type\n");
	printf("4. Sort by volumn\n");
	printf("5. Sort by weight\n");
	printf("==============================\n");
	printf("Please select an option :\n");
}

void openFileandShowData()
{
	FILE *fp = NULL;
	Err_type err;
	err = fopen_s(&fp,FILEDATA,"r");
	if(err != 0)
		printf("File couldn't be opened!\n");
	else
	{
		size = readData(data,fp);
		printData(data,size);
		fclose(fp);
	}
}

void dataOperation()
{
	int select,id;

	if(size == 0)
		printf("No data! Please read data from file.\n");
	while(1)
	{
		operationMenu();
		scanf("%d",&select);
		if(select == 0)
		{
			printf("Return to Main Menu\n");
			break;
		}
		switch(select)
		{
			case SHOW:
				printData(data,size);
				break;
			case APPEND:
				appendData(data,&size);
				size++;
				printData(data,size);
				break;
			case UPDATE:
				printf("Enter the ID for updating data : ");
				scanf("%d",&id);
				updateData(data,size,id);
				printData(data,size);
				break;
			case DELETE:
				printf("Enter the ID of data : ");
				scanf("%d",&id);
				deleteData(data,&size,id);
				size--;
				printData(data,size);
				break;
			default:
				break;
		}

	}
}

void sortOperation()
{
	int select;
	if(size == 0)
		printf("No data! Please read data from file.\n");
	while(1)
	{
		sortMenu();
		scanf("%d",&select);
		if(select == 0)
		{
			printf("Return to Main Menu\n");
			break;
		}
		sortData(data,size,(S_Method)select);
		printData(data,size);
	}
}

void writeFile()
{
	FILE *wfp;
	Err_type err;
	if(size == 0)
		printf("No data! Please read data from file.\n");
	for(int i = 1;i <= 5;i++)
	{
		sortData(data,size,(S_Method)i);
		err = fopen_s(&wfp,filePath[(S_Method)i],"w");
		if(err != 0)
			printf("File couldn't be opened!\n");
		else
		{
			writeDatatoSingleFile(data,size,wfp);
			fclose(wfp);
		}
	}
}

int readData(objdata obj[],FILE *fp)
{
	int i = 0;
	char temp[20];

	while(!feof(fp))
	{
		fscanf(fp,"%d",&(obj[i].id));
		if(obj[i].id == 0)
			break;
		fscanf(fp,"%s",temp,20);
		obj[i].otype = strToObjectType(temp);
		fscanf(fp,"%s",temp,20);
		obj[i].mtype = strToMaterialType(temp);
		fscanf(fp,"%f",&(obj[i].para1));
		fscanf(fp,"%f",&(obj[i].para2));
		checkData(&obj[i]);
		i++;
	}
	return i;
}

Otype strToObjectType(char str[])
{
	if(strcmp(str,"Ball") == 0)
		return BALL;
	else if(strcmp(str,"Cube") == 0)
		return CUBE;
	else if(strcmp(str,"Pyramid") == 0)
		return PYRAMID;
	else if(strcmp(str,"Cylinder") == 0)
		return CYLINDER;
	else
		return OBJECT_UNKNOWN;
}

Mtype strToMaterialType(char str[])
{
	if(strcmp(str,"Aluminum") == 0)
		return ALUMINUM;
	else if(strcmp(str,"Iron") == 0)
		return IRON;
	else if(strcmp(str,"Lead") == 0)
		return LEAD;
	else
		return MATERIAL_UNKNOWN;
}

double Volumn(objdata obj)
{
	double volumn;
	if((obj.etype == ERR_OBJECT) || (obj.etype == ERR_PARA1) || (obj.etype == ERR_PARA2))
		return 0;
	switch(obj.otype)
	{
		case BALL:
			volumn = 4.0/3*(obj.para1)*(obj.para1)*(obj.para1);
			break;
		case CUBE:
			volumn = (obj.para1)*(obj.para1)*(obj.para1);
			break;
		case CYLINDER:
			volumn = PI*(obj.para1)*(obj.para1)*(obj.para2);
			break;
		case PYRAMID:
			volumn = 1.0/3*(obj.para1)*(obj.para1)*(obj.para2);
			break;
		default:
			volumn = 0;
			break;
	}
	return volumn;
}

double Weight(objdata obj)
{
	if(obj.etype == ERR_MATERIAL)
		return 0;
	else
		return density[obj.mtype]*Volumn(obj);
}

void printData(objdata obj[],int size)
{
	printf("********************************Display Data********************************\n");
	printf("%4s %10s %10s %9s %9s %9s %9s %9s\n","ID","Object","Material","Para1","Para2","Volumn","Weight","Error");
	for(int i = 0;i < size;i++)
		printf("%4d %10s %10s %9.3f %9.3f %9.3f %9.3f %9s\n",obj[i].id,objType[obj[i].otype],materialType[obj[i].mtype],obj[i].para1,obj[i].para2,Volumn(obj[i]),Weight(obj[i]),errorType[obj[i].etype]);
	printf("****************************************************************************\n");
}

void appendData(objdata obj[],int *size)
{
	int id,index;
	printf("Please input the properties of new object :\n");
	printf("ID : ");
	scanf("%d",&id);
	index = searchData(obj,*size,id);
	if(index != -1)
		printf("ID exist!\n");
	else
	{
		obj[*size].id = id;
		printf("Object type (1.Ball  2.Cube  3.Pyramid  4.Cylinder) : ");
		scanf("%d",&(obj[*size].otype));
		printf("Material type (1.Iron  2.Aluminum  3.Lead) : ");
		scanf("%d",&(obj[*size].mtype));
		printf("Para1 : ");
		scanf("%f",&(obj[*size].para1));
		if((obj[*size].otype == PYRAMID) || (obj[*size].otype == CYLINDER))
		{
			printf("Para2 : ");
			scanf("%f",&(obj[*size].para2));
		}
		else
			obj[*size].para2 = 0;
		checkData(&obj[*size]);
		size++;
	}
}

void updateData(objdata obj[],int size,int id)
{
	int index = searchData(obj,size,id);

	if(index == -1)
		printf("ID doesn't exist!\n");
	else
	{
		printf("Please update the properties of object %d :\n",obj[index].id);
		printf("Object type (1.Ball  2.Cube  3.Pyramid  4.Cylinder) : ");
		scanf("%d",&(obj[index].otype));
		printf("Material type (1.Iron  2.Aluminum  3.Lead) : ");
		scanf("%d",&(obj[index].mtype));
		printf("Para1 : ");
		scanf("%f",&(obj[index].para1));
		if((obj[index].otype == PYRAMID) || (obj[index].otype == CYLINDER))
		{
			printf("Para2 : ");
			scanf("%f",&(obj[index].para2));
		}
		else
			obj[index].para2 = 0;
	}
	checkData(&obj[size]);	
}

void deleteData(objdata obj[],int *size,int id)
{
	int index = searchData(obj,*size,id);

	if(index == -1)
		printf("ID doesn't exist!\n");
	else
	{
		for(int i = index;i < *size;i++)
			obj[i] = obj[i+1];
			size--;
	}
}

void checkData(objdata *obj)
{
	if(obj->otype == 0)
		obj->etype = ERR_OBJECT;
	else if(obj->mtype == 0)
		obj->etype = ERR_MATERIAL;
	else if(obj->para1 < 0)
		obj->etype = ERR_PARA1;
	else if(obj->para2 < 0)
		obj->etype = ERR_PARA2;
	else
		obj->etype = NORMAL;
}

int Compare(objdata obj1,objdata obj2,S_Method method)
{
	switch(method)
	{
		case SORT_BY_ID:
			if(obj1.id < obj2.id)
				return 1;
			break;
		case SORT_BY_OBJECT:
			if(obj1.otype < obj2.otype)
				return 1;
			break;
		case SORT_BY_MATERIAL:
			if(obj1.mtype < obj2.mtype)
				return 1;
			break;
		case SORT_BY_VOLUMN:
			if(Volumn(obj1) < Volumn(obj2))
				return 1;
			break;
		case SORT_BY_WEIGHT:
			if(Weight(obj1) < Weight(obj2))
				return 1;
			break;
		default:
			break;
	}
	return 0;
}

void sortData(objdata obj[],int size,S_Method method)
{
	for(int pass = 1;pass < size;pass++)
	{
		for(int i = 0;i < size - pass;i++)
		{
			if(Compare(obj[i],obj[i+1],method) == 1)
				Swap(&obj[i],&obj[i+1]);
		}
	}
}

void Swap(objdata *obj1,objdata *obj2)
{
	objdata temp;

	temp = *obj1;
	*obj1 = *obj2;
	*obj2 = temp;
}

void writeDatatoSingleFile(objdata obj[],int size,FILE *fp)
{
	fprintf(fp,"%4s %10s %10s %9s %9s %9s %9s\n","ID","Object","Material","Para1","Para2","Volumn","Weight");
	for(int i = 0;i < size;i++)
		fprintf(fp,"%4d %10s %10s %9.3f %9.3f %9.3f %9.3f\n",obj[i].id,objType[obj[i].otype],materialType[obj[i].mtype],obj[i].para1,obj[i].para2,Volumn(obj[i]),Weight(obj[i]));
}

int searchData(objdata obj[],int size,int id)
{
	for(int index = 0;index < size;index++)
	{
		if(obj[index].id == id)
			return index;
	}
	return -1;	
}

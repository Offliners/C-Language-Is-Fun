#include<stdio.h>
#include<string.h>

int main()
{
	char str[10][50],temp[50];

	printf("Enter 10 words :\n");
	for(int i = 0;i < 10;i++)
		scanf("%s[^\n]",str[i]);
	for(int j = 0;j < 9;j++)
	{
		for(int k = j + 1;k < 10;k++)
		{
			if(strcmp(str[j],str[k]) > 0)
			{
				strcpy(temp,str[j]);
				strcpy(str[j],str[k]);
				strcpy(str[k],temp);
			}
		}
	}
	printf("\nIn lexicographical order :\n");
	for(int t = 0;t < 10;t++)
		puts(str[t]);
	return 0;
}
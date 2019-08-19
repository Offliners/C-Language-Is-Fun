#include<stdio.h>

int main()
{
	char line[150];
	int vowel,consonant,digit,space;
	vowel = consonant = digit = space = 0;
	
	printf("Enter a line of string : ");
	scanf("%[^\n]",line);
	for(int i = 0;line[i] != '\0';i++)
	{
		if(line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u' || line[i] == 'A' || line[i] == 'E' || line[i] == 'I' || line[i] == 'O' || line[i] == 'U')
			vowel++;
		else if((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))
			consonant++;
		else if(line[i] >= '0' && line[i] <= '9')
			digit++;
		else if(line[i] == ' ')
			space++;
	}
	printf("Vowels : %d\n",vowel);
	printf("Consonants : %d\n",consonant);
	printf("Dights : %d\n",digit);
	printf("White spaces : %d\n",space);
	return 0;
}
#include<stdio.h>

int main()
{
	char c;
	int Lowercase,Uppercase;

	printf("Enter an alphabet : ");
	scanf("%c",&c);
	Lowercase = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
	Uppercase = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
	if (Lowercase || Uppercase)
		printf("%c is a vowel.",c);
	else
		printf("%c is a consonant.",c);
	return 0;
}
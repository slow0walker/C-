#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define W_L  26 

void read_word(int counts[])
{
	char word[W_L] = "";
	int i = 0;
	while ((word[i] = getchar()) != '\n' && i < W_L - 1)
	{
		if (isalpha(word[i]))
		{
			counts[tolower(word[i]) - 'a']++;
		}
		i++;
	}
	word[i] = '\0';
}

bool equal_array(int counts1[], int counts2[])
{
	int i = 0;
	for (int i = 0; i < W_L; i++)
	{
		if (counts1[i] != counts2[i])return false;
	}
	return true;
}

int main()
{
	
	int word_cout1[26] = { 0 };
	int word_cout2[26] = { 0 };
	printf("Enter first word:");
	read_word(word_cout1);
	printf("Enter second word: ");
	read_word(word_cout2);

	bool flag = equal_array(word_cout1, word_cout2);
	if (flag) {
		printf("The words are anagrams.\n");
	}
	else {
		printf("The words are not anagrams.\n");
	}
	return 0;

}
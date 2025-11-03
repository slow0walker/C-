#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define W_L  26  //单词的最大长度

int main()
{
	int word_cout[26] = { 0 };
	char word1[W_L]="";
	char word2[W_L]="";

	int i = 0;
	char ch;
	printf("Enter first word:");
	while ((word1[i] = getchar()) != '\n' && i < W_L - 1)
	{
		if (isalpha(word1[i]))
		{
			word_cout[tolower(word1[i]) - 'a']++;
		}
		i++;
	}
	word1[i] = '\0';

	printf("Enter second word: ");
	i = 0;
	while ((word2[i] = getchar()) != '\n' && i < W_L - 1) {
		if (isalpha(word2[i])) {
			word_cout[tolower(word2[i]) - 'a']--;
		}
		i++;
	}
	word2[i] = '\0';

	bool is_anagram = true;

	for (int j = 0; j < W_L; j++)
	{
		if (word_cout[j] != 0)
		{
			is_anagram = false;
			break;
		}
	}
	if (is_anagram) {
		printf("The words are anagrams.\n");
	}
	else {
		printf("The words are not anagrams.\n");
	}

	return 0;
}

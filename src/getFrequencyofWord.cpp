/*

Problem : Return the Count of how many times the word occurred
in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>
#include<string.h>
#include<stdio.h>
void computeLPSArray(char *pat, int M, int *lps);
void Find(char*, char*, int Mptr, int* count);
void FindCount(char *pat, char *txt, int *count)
{
	int M = strlen(pat);
	int N = strlen(txt);

	int *lps = (int *)malloc(sizeof(int)*M);
	int j = 0;  // index for pat[]

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, M, lps);

	int i = 0;  // index for txt[]
	while (i < N)
	{
		if (pat[j] == txt[i])
		{
			j++;
			i++;
		}

		if (j == M)
		{
			//printf("Found pattern at index %d \n", i - j);
			(*count)++;
			j = lps[j - 1];
		}

		// mismatch after j matches
		else if (i < N && pat[j] != txt[i])
		{
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
	free(lps);
}

void computeLPSArray(char *pat, int M, int *lps)
{
	int len = 0;
	int i;

	lps[0] = 0; // lps[0] is always 0
	i = 1;
	while (i < M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			if (len != 0)
			{

				len = lps[len - 1];


			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
int count_word_in_str_way_1(char *str, char *word){
	//init checking
	if (str == NULL || word == NULL) return NULL;

	int count = 0;
	FindCount(word, str, &count);
	return count;
}
void Find(char *statement, char *pattn, int Mptr, int *count){

	int mptr = Mptr;
	int pptr = 0;


	while (statement[mptr] != '\0'){

		if (pattn[pptr] == statement[mptr]){
			pptr++;
			mptr++;
			if (pattn[pptr] == '\0') break;
		}
		else{
			pptr = 0;
			mptr++;
		}
	}
	if (pattn[pptr] == '\0') {
		*count = *count + 1;
		if (pattn[1] == '\0')   Find(statement, pattn, mptr, count);
		else Find(statement, pattn, mptr - 1, count);
	}
	else return;
}
int count_word_int_str_way_2_recursion(char *str, char *word){
	int count = 0;

	Find(str, word, 0, &count);

	return count;
}


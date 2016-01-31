/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stddef.h>
#include <stdlib.h>
#include<stdio.h>
int strlen_last_word(char *cp){
	int count;
	for (count = 0; cp[count] != '\0'; count++);
	return count;
}
char * get_last_word(char * str){

	if (str == NULL)
		return NULL;

	char *result = (char*)malloc(sizeof(char)*strlen_last_word(str));

	int pointer1 = 0;
	int pointer2 = -1;
	int t = 0;
	for (pointer1 = 0; str[pointer1] != '\0'; pointer1++){
		if (str[pointer1] == ' ') pointer2 = pointer1;
	}


	for (int i = pointer2 + 1; str[i] != '\0'; i++) {
		result[t++] = str[i];
	}
	result[t] = '\0';
	return result;
}

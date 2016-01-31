/*
OVERVIEW: Given a string, Return the substring of the main string
from i index to j index
Indexes start from 0,ith letter and jth letter are included
E.g.: Input: "get_sub_string("abcdefgh",2,5) , Output: "cdef"

INPUTS: A string.

OUTPUT: return substring from [i,j]

INPUT2: I will Code for Mission RnD , 2,10
OUTPUT2:will Code

NOTES: Check Null Strings ,Include stddef for NULL if needed.Create a New string and return it ,dont modfiy
original String
*/

#include <stddef.h>
#include <stdlib.h>
#include<stdio.h>
char* Result(char*, int i, int j);
int strlen(char *cp){
	int count;
	for (count = 0; cp[count] != '\0'; count++);
	return count;
}
char * get_sub_string(char *str, int i, int j){

	//init checking
	if (i > j) return NULL;
	if (str == NULL)
		return NULL;

	//copying so not to change the original string
	char *t = (char*)malloc(sizeof(char)*strlen(str));
	for (int i = 0; str[i] != '\0'; i++) t[i] = str[i];

	return Result(t, i, j);

}
//getting the sub string
char* Result(char *cp, int i, int j){
	char *tmp;
	tmp = &cp[i];
	tmp[j + 1] = '\0';
	return tmp;
}

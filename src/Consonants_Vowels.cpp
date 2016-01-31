/*
OVERVIEW: Given a string, Count the number of consonants and vowels
and copy them to 'consonants' and 'vowels' respectively
Notes : Neglect Space and Other Symbols .Consider Capital Letters too

E.g.: Input: "aB c" , Output: consonants should contain 2 and vowels 1

INPUTS: A string and two int pointers

OUTPUT: Modify the consonants and vowels pointers accordingly with their counts (*consonants=?? ;*vowels=??)

INPUT2: Dont Forget they are pointers ;consonants and vowels are addresses of two variables .

Output: consonants should be ??,vowels should be ??

??:Count them :)

NOTES: Don't create new string , Dont return anything ,you have been given two pointers ,copy values into those .
*/

#include <stddef.h>
#include<stdio.h>
#include<malloc.h>
struct node
{
	char letter;
	node* left;
	node* right;
};
struct node* insert(struct node* r, int data)
{
	if (r == NULL)
	{
		r = (struct node*) malloc(sizeof(struct node));
		r->letter = data;
		r->left = NULL;
		r->right = NULL;
	}
	else if (data == r->letter) return r;
	else if (data < r->letter){
		r->left = insert(r->left, data);
	}
	else {
		r->right = insert(r->right, data);
	}
	return r;

}
void Count(struct node* r, char c, int *consonants, int *vowels);
void count_vowels_and_consonants(char *str, int *consonants, int *vowels){

	//init checking
	if (str == NULL) {
		*consonants = 0;
		*vowels = 0;
	}
	else{
		char ref[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U', '\0' };
		*consonants = 0;
		*vowels = 0;

		struct node* root;
		root = NULL;

		for (int i = 0; ref[i] != '\0'; i++){
			root = insert(root, ref[i]);
		}

		for (int i = 0; str[i] != '\0'; i++){
			if (str[i] == ' ') continue;
			Count(root, str[i], consonants, vowels);
		}
	}



}
void Count(struct node* r, char c, int *consonants, int *vowels){
	if (r != NULL){
		if (r->letter == c || r->letter == c + 32)//decreasing number of comparsions
		{
			//vowels found
			(*vowels)++;
			return;
		}
		else if (r->letter > c) Count(r->left, c, consonants, vowels);
		else Count(r->right, c, consonants, vowels);
	}
	else if (c >= 65 && c <= 90 || c >= 97 && c <= 122){
		(*consonants)++;
		return;
	}
	return;
}


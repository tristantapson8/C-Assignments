// Author: Tristan Tapson tapsonte

#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 100

// function prototypes
void printLatinWord(char *token, int sizeT);

// main function
int main(void){

	puts(" ");
	puts("Lets do some pig latin! Input rules found below:\n");
	puts("- You can enter a string of words separated by a space");
	puts("- Word size must be two or more characters");
	puts("- The string must start or end with a word\n");

	// input string (max of 100 characters for simplicity)
	char inputString[MAX];
	printf("Enter a string (max of 100 chars): ");
	scanf("%[^\n]", &inputString);
	printf("User input string: %s\n", inputString);

	int sizeS = (unsigned)strlen(inputString);
	printf("User input string is (%u) characters long\n\n", sizeS);
	
	// split user string based on space character
	const char splitChar[2] = " ";

	// token pointer
	char *token;
	// tokenizing using strtok
	token = strtok(inputString, splitChar);

	// print tokenized string
	while( token != NULL ){
		printf("token: %s\n", token);

		int sizeT = (unsigned)strlen(token);
		printf("token is (%u) characters long\n", sizeT);

		// convert to pig latin, passing in the split string as a token pointer
		printLatinWord(token, sizeT);
		token = strtok(NULL, splitChar);
	}
}

// prints the pig latin word
void printLatinWord(char *token, int sizeT){

	int i;

	// printing everything but the first character in the token
	printf("pig-latin token: ");
	for(i = 1; i < sizeT;i++){
		printf("%c", token[i]);
	}

	// print the first character in the token, then add "ay"
	printf("%c", token[0]);
	puts("ay\n");
}




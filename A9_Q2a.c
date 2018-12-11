// Author: Tristan Tapson tapsonte

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

// max stack size; can be anything, just a small size for testing
#define MAX 100

// global variables stack size and stack
int top =-1;
char stack[MAX];

// function prototypes
int convertToAscii(char input);
void push(char ch);
void display();
int isPalindrome(char stack[], int min, int max);

// converts a character to its ascii table decimal value
int convertToAscii(char input){
	int converted = (int)input;
	return converted;
}

// pushes an element ch onto the top of the stack
void push(char ch){

	// full stack message
    	if (top == MAX-1){
        	printf("\nStack full!");
    	}

	// user input is added, stack size increased by 1
    	else{
        	top = top+1;
        	stack[top] = ch;
    	}
}

// isPalindrome returns 1 if string is a palindrome, 0 otherwise
int isPalindrome(char stack[], int min, int max){

	// start index past half way point (palindrome = true)
	if(min >= max){
		return 1;
	}

	// opposite index values are equal
	else if(stack[min] == stack[max]){
		// continue to check the stack at the next indexes
		return isPalindrome(stack, min+1, max-1);
	}

	// none of a the above checks are met while walking through the stack?
	// then stack does not contain a palindrome
	else{
		return 0;
	}

}

// display prints all the contents currently on the stack
void display(){

    	int i;
    
	// empty stack message
    	if(top == -1){
        	printf("\nStack is empty.\n");
    	}
		
	// print the stack contents
    	else{
        	puts("");
        	printf("Stack is: ");
        	for(i = 0; i <= top; ++i){
            		printf("%c -> ", stack[i]);
        	}
        	puts("NULL\n");
    	}
}
  
// main function
int main(){ 

	int i;
	int len;
	int j;
	char str[MAX];
    
	// user instructions 
	puts(" ");
    	puts("Welcome. This program is a palindrome checker for a stack of characters!");
    	puts(" * The stack size limit for this program is 100 characters");
        puts(" * Left to right = top of stack to bottom of stack");
	puts(" * Spaces and punctuation are ignored for the palindrome check");
    
	printf("\nEnter text: ");
	fgets(str, MAX, stdin);

	// length of the string
	len = strlen(str);
	
	// walk through the string
	for(i = 0; i < len; i++){

		int ch = convertToAscii(str[i]);
		
		// only push characters 'A-Z' & 'a-z' onto the stack from the string
		if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)){
			
			// printf("ascii num is: %d, allow: %c\n",convertToAscii(str[i]), str[i]);
			push(str[i]);

		}

		else{
			// do nothing
		}
	}

	// display stack contents
	display();
    	
	// check if stack contains a palindrome
	if(isPalindrome(stack, 0, top) == 1){
		puts("Stack contains a palindrome!");
		printf("\"");

		for(j = 0; j < len; j++){
			if (j < len-1){
		 		printf("%c", str[j]);
			}
			else{
				puts("\" is a palindrome!\n");
			}
		}
	}

	// otherwise not a palindrome
	else{
		puts("Stack does not contain a palindrome...");
		printf("\"");

		for(j = 0; j < len; j++){
			if (j < len-1){
		 		printf("%c", str[j]);
			}
			else{
				puts("\" is not a palindrome...\n");
			}
		}
	}
	
	return 0; 
} 	









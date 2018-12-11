// Author Tristan Tapson tapsonte

#include <stdio.h>
#include <stdlib.h>

// maximum characters in list
#define MAX 10

// global variable for list size
int size = 0;

struct listNode {
	char data;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

// function prototypes
void insert(ListNodePtr *sPtr, char value);
void reverseList(ListNodePtr *sPtr); // function to reverse a linked list
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);

// main function
int main(void){
	
	ListNodePtr startPtr = NULL;
	char item;

	// user instructions 
	puts(" ");
    	puts("Welcome. This program is a linked list reverser!\n");
	puts("* 10 characters will be entered into the list by the user");
	puts("  one-by-one until the list size limit of (10) is reached\n");
    	puts("* Once 10 characters has been entered into the list by the");
        puts("  user, the list will be reversed and its reversed contents");
	puts("  will be displayed\n");

	// continue asking for user input until list size is reached
	// display list contents after each list input
	while(size < MAX){
		printf("%s", "Enter a character: ");
		scanf("\n%c", &item);
		puts("The list is: ");
		insert(&startPtr, item);
		printList(startPtr);
	}

	// once list size is reached, reverse the list and display the contents,
	// then exit the program
	if(size >= MAX){
		puts("Reversing list...");
		puts("The list in reverse is: ");
		reverseList(&startPtr);
		printList(startPtr);
		puts("End of run.\n"); 
		exit(0); 
	}
}

void insert(ListNodePtr *sPtr, char value){

	ListNodePtr newPtr = malloc(sizeof(ListNode));

	if (newPtr != NULL){
		newPtr->data = value;
		newPtr->nextPtr = NULL;

		ListNodePtr previousPtr = NULL;
		ListNodePtr currentPtr = *sPtr;

		while(currentPtr != NULL && value > currentPtr->data){
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if(previousPtr == NULL){
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
			size++;
		}
		else{
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
			size++;
		}
	}
	else{
		printf("%d not inserted. No memory available.\n", value);
	}
}


// reverse modifies the pointers in a linked list so that the list is reversed
void reverseList(ListNodePtr *sPtr){
	
	ListNodePtr previousPtr = NULL;
	ListNodePtr currentPtr = *sPtr;
	ListNodePtr nextPtr;

	// walk through the linked list pointers until NULL pointer reached
	while(currentPtr != NULL){
		// update the next pointer
		nextPtr = currentPtr->nextPtr;
		// reverse the pointer of the current list item to point to previous list item
		currentPtr->nextPtr = previousPtr;
		// update the pointers by one list item, and repeat until NULL
		previousPtr = currentPtr;
		currentPtr = nextPtr;
	}

	*sPtr = previousPtr;
}


int isEmpty(ListNodePtr sPtr){
	return sPtr == NULL;
}

void printList(ListNodePtr currentPtr){

	if(isEmpty(currentPtr)){
		puts("List is empty. \n");
	}

	else{
		while(currentPtr != NULL){
			printf("%c --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		
		puts("NULL\n");
	}
}
	










		
	










































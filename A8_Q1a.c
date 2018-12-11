// Author Tristan Tapson tapsonte

#include <stdio.h>
#include <stdlib.h>

struct listNode {
	char data;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

// function prototypes
void insert(ListNodePtr *sPtr, int value);
char delete(ListNodePtr *sPtr, int value);
int searchList(ListNodePtr *sPtr, int value);	// searchList prototype
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);

int main(void){
	
	ListNodePtr startPtr = NULL;
	int item;

	instructions();
	printf("%s", "? ");
	unsigned int choice;
	scanf("%u", &choice);

	while (choice != 3){
		switch (choice){
			case 1:
				printf("%s", "Enter an integer: ");
				scanf("\n%d", &item);
				insert(&startPtr, item);
				printList(startPtr);
				break;
			case 2:
				if(!isEmpty(startPtr)){
					printf("%s", "Enter integer to be recursively searched for: ");
					scanf("\n%d", &item);
					
					// return value of searchList being 0 means item is in list
					if(searchList(&startPtr, item) == 0){
						printf("%d is in the list. \n\n",item);
						//printList(startPtr);
					}
					// otherwise the item is not in the list
					else{
						printf("%d is not in the list. \n\n",item);
					}
				}
				else{
					puts("List is empty. \n");
				}

				break;

			default:
				puts("Invalid choice. \n");
				instructions();
				break;
		}

		printf("%s", "? ");
		scanf("%u", &choice);
	}
	puts("End of run.");
}

void instructions(void){
	puts(" ");
	puts("Enter your choice: \n"
		"1 to insert an element into the list.\n"
		"2 to recursively search an element from the list.\n"
		"3 to end.");
	puts(" ");
}

void insert(ListNodePtr *sPtr, int value){

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
		}
		else{
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else{
		printf("%d not inserted. No memory available.\n", value);
	}
}

char delete(ListNodePtr *sPtr, int value){

	if(value == (*sPtr)->data){
		ListNodePtr tempPtr = *sPtr;
		*sPtr = (*sPtr)->nextPtr;
		free(tempPtr);
		return value;
	}

	else{
		ListNodePtr previousPtr = *sPtr;
		ListNodePtr currentPtr = (*sPtr)->nextPtr;

		while(currentPtr != NULL && currentPtr->data != value){
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}


		if(currentPtr != NULL){
			ListNodePtr tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free(tempPtr);
			return value;
		}
	}

	return '\0';
}

// searchList searches recursively for an integer in a linked list
// note: commented out print statements were used for testing
int searchList(ListNodePtr *sPtr, int value){

	// pseudoBoolean to track if an item is in the list
	// 0 for search found, 1 for list traversed with search value missing
	int found = 0;

	// base cases, either list has been recursed through (1),
	// or the value of the current pointer is not the search value (2)

	// base case 1
	if(isEmpty(*sPtr)){
		//printf ("%d is not in the list\n", value);
		found++;
		return found;
	}

	// base case 2
	else if(value == (*sPtr)->data && found == 0){
		//puts("found at the current ptr to the head");
		//printf ("%d is in the list\n", value);
		return found;
	}

	else {
		if(sPtr != NULL && found == 0){
			//puts ("head is not empty, but value not found; continue searching");

			// recursive step, check the next pointer value
			searchList(&(*sPtr)->nextPtr, value);
		}
	}
}


int isEmpty(ListNodePtr sPtr){
	return sPtr == NULL;
}

void printList(ListNodePtr currentPtr){

	if(isEmpty(currentPtr)){
		puts("List is empty. \n");
	}

	else{
		puts("The list is: ");

		while(currentPtr != NULL){
			printf("%d --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		
		puts("NULL\n");
	}
}
	










		
	










































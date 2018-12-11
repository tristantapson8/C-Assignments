// Author: Tristan Tapson tapsonte
// note: stack structure in this program represents the right most value as the stack top

#include <stdio.h> 
#include <stdlib.h>

// max stack size; can be anything, just a small size for testing
#define MAX 6

// global variables stack size and stack
int top =-1, stack[MAX];

// function prototypes
void push();
void pop();
int findMiddle(int stack[]);
void delete(int stack[], int el);
void display();

// pushes an element onto the top of the stack
void push(){

	int val;

	// full stack message
    	if (top == MAX-1){
        	printf("\nStack full!");
    	}

	// user input is added, stack size increased by 1
    	else{
          	printf("\nEnter element to push: ");
        	scanf("%d", &val);
        	top = top+1;
        	stack[top] = val;
    	}
}

// pops an element off the top of the stack
void pop(){

	// empty stack message
    	if(top == -1){
        	//puts ("\nStack is empty.\n");
    	}

	// stack top is removed, stack size reduced by 1
    	else{
        	printf("\nDeleted element %d.", stack[top]);
        	top = top-1;
    	}
}

// findMiddle returns the middle element on the stack
int findMiddle(int stack[]){

    	int i;
    
	// empty stack message
    	if(top == -1){
        	printf("\nStack is empty.\n");
    	}
    
	// search for the middle element on the stack
    	else{
        	puts(" ");
        	puts("Checking middle element on stack!");
        
        	int popIndex = (top+1)/2;
        	printf("Pop from index: %d\n", popIndex);
        
		// iterate through the stack until the popIndex is reached
        	for(i = 0; i <= top; ++i){
           	 	if(i == popIndex ){
                		printf("Element to be popped: %d\n", stack[i]);
                		return stack[i];
               			// break;
            		}
        	}

        	puts(" ");
    	}
}

// deletes an element el from the stack regardless of location on the stack
void delete(int stack[], int el) { 
    
	// empty stack
	if(top == -1){
        	//puts ("\nStack is empty.\n");
    	}
    
	// delete an element from the stack
    	else{
   
        	int i;
		int j;

		// search for the element on the stack
        	for (i = 0; i < top; i++){
           		if (stack[i] == el){
                		break; 
  			}
		}
        
        	if (i < top) { 
		    	// modify after deleted index values
            		for (j = i; j < top; j++){
               	 		stack[j] = stack[j+1]; 
        		}
		}
  
	// array size reduced by 1 after deleting
        puts("Deleting middle element from stack...");
        top = top-1;
        
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
            		printf("%d ", stack[i]);
        	}
        	puts(" ");
    	}
}
  
// main function
int main(){ 

	int choice;
    
	// user instructions 
	puts(" ");
    	puts("Welcome. This program is a stack simulator!");
    	puts("The stack size limit for this program is 6");
        puts("Left to right = bottom of stack to top of stack");
        puts("Here are some of the commands you can do on the stack simulator:");
        puts(" * 1: push");
        puts(" * 2: pop");
        puts(" * 3: display stack contents");
        puts(" * 4: find the middle value on the stack");
        puts(" * 5: delete the middle value from the stack");
        puts(" * 6: end program");
    
	// continue to ask for user input until the program is ended
	while(1){
           
        	puts(" ");
            	printf("Enter your choice (from 1-6): ");
            	scanf("%d", &choice);
            
            	switch(choice){
                	case 1: push(); display(); break;
                	case 2: pop(); display(); break;
                	case 3: display(); break;
                	case 4: findMiddle(stack); break;
                	case 5: delete(stack, findMiddle(stack)); display(); break;
                	case 6: puts("End of run.\n"); exit(0); 
                	default: puts("Invalid choice.");
            	}
    	}
 
	return 0; 
} 	









// Author: Tristan Tapson tapsonte

#include <stdio.h>

// function prototypes
int multiples(int num1, int num2);

// main function
int main(int argc, char *argv[]){

	int num1, num2;

	printf("%s\n", "Please enter Integer1: ");
	scanf("%d", &num1);
	printf("%s\n", "Please enter Integer2: ");
	scanf("%d", &num2);

	// print statement to declare if num2 is or is not a multiple of num1

	// if they are multiples
	if(multiples(num1, num2) == 1){
		printf("Integer2 - (%d", num2);
		printf(") IS a multiple of Integer1 - (%d", num1);
		printf(")\n");
	}
	
	// if they are NOT multiples
	else{
		printf("Integer2 - (%d", num2);
		printf(") is NOT a multiple of Integer1 - (%d", num1);
		printf(")\n");
	}
	
}

// checks to see if num2 is a multiple of num1
int multiples(int num1, int num2){

	// return 1 if it is a multiple
	if(num1 % num2 == 0){
		return 1;
	} 

	// return 0 otherwise
	else{
		return 0;
	}
}




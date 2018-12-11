// Author: Tristan Tapson tapsonte

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function prototypes
void printArray(int arr[], int arrSize);
int getMax(int num1, int num2);
int findMax(int arr[], int arrSize, bool printable);

// main function 
int main(void){

	unsigned int number;
	unsigned int i;
	unsigned int arrSize;
	
	puts(" ");
	puts("Get the maximum value of your integer array using recursion!");
	printf("%s", "Enter the size of your array: ");
	scanf ("%d", &arrSize);
	
	int arr[arrSize];

	// populating the array
	for(i = 0; i < arrSize; i++){
		printf("Enter the %dth number: ", i);
		scanf("%d", &number);
		arr[i] = number;
	}

	// printing populated array
	puts("");
	puts("Values found in array after initializing: ");
	printArray(arr, arrSize);

	// printing max array value
	if(arrSize > 0){
		printf("The maximum value found in this array is: %d\n\n", findMax(arr, arrSize, true));
	}
	// if array size is 0
	else{
		printf("No maximum value can be found for an array with zero (0) entries\n\n");
	}

}

// prints values in Array
void printArray(int arr[], int arrSize){

	unsigned int i;

	printf("[");
	for(i = 0; i < arrSize; i++){

		// formatting brackets and commas
		if(i< arrSize-1){
			printf("%d,", arr[i]);
		}
		else{
			printf("%d", arr[i]);
		}
	}
	printf("]\n");
	//puts(" ");
}

// return the bigger number between two integers
int getMax(int num1, int num2){
	if(num1 > num2){
		return num1;
	}
	else{
		return num2;
	}	
}

// returns the maximum value in an array
int findMax(int arr[], int arrSize, bool printable){

	// if not an empty array
	if(printable == true){

		// "desize" the array by getting max from 0 to size-1 on each recursion
		// recursive step to find the maximum value
		if(arrSize > 1){
			return getMax(arr[arrSize-1], findMax(arr, arrSize-1, true));
		}

		// base case
		else {
			return *arr;
		}
	}
}
















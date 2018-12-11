// Author: Tristan Tapson tapsonte

#include <stdio.h>

// function prototypes
void printArray(int arr[], int arrSize);
int* findUnique(int arr[], int trackArr[], int arrSize);
void printUnique(int arr[], int trackArr[], int arrSize);

// main function 
int main(void){

	unsigned int number;
	unsigned int i;
	unsigned int arrSize;
	
	puts(" ");
	puts("Find all the unique elements in an array of integers!");
	printf("%s", "Enter the size of your array: ");
	scanf ("%d", &arrSize);
	
	int arr[arrSize];
	int trackArr[arrSize];
	
	// populate the initial array and tracker array
	for(i = 0; i < arrSize; i++){
		printf("Enter the %dth number: ", i);
		scanf("%d", &number);
		arr[i] = number;
		trackArr[i] = 0;
	}

	// printing populated array
	puts("");
	puts("Values found in array after initializing: ");
	printArray(arr, arrSize);

	// printing unique element indexes
	puts("Tracking unique indexes: ");
	printArray(findUnique(arr, trackArr, arrSize), arrSize);
	
	// printing unique elements
	printUnique(arr, trackArr, arrSize);

}


// prints values in Array
void printArray(int arr[], int arrSize){

	unsigned int i;

	
	printf("[");
	for(i = 0; i < arrSize; i++){
		// formating brackets and commas
		if(i< arrSize-1){
			printf("%d,", arr[i]);
		}
		else{
			printf("%d", arr[i]);
		}
	}
	printf("]\n");
	puts(" ");
}

// finds all the unique elements in an array
int* findUnique(int arr[], int trackArr[], int arrSize){

	unsigned int i;
	unsigned int j;

	//puts("Unique values found in array: ");
	printf("(A zero (0) value means that the element at this index is unique!)");

	for(i = 0; i < arrSize; i++){
		for(j = 0; j < arrSize; j++){

			// dont compare the same index
			if(i != j){
				// if duplicate values
				if(arr[i] == arr[j] ){
					// mark tracking array as 1 (true) for non-unique
					trackArr[i] = 1;
					trackArr[j] = 1;
				}
			}
		}
	}
	puts(" ");
	return trackArr;
}

// prints all the unique elements
void printUnique(int arr[], int trackArr[], int arrSize){
	unsigned int i;

	printf("The unique element(s) found in this array:\n");
	
	// print elements marked as 0 (false) for unique
	for(i = 0; i < arrSize; i++){
		if(trackArr[i] == 0){
			printf("%d ", arr[i]);
		}
	}

	puts(" ");
}













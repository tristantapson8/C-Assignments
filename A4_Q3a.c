// Author: Tristan Tapson tapsonte

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void printArray(int arr[], int arrSize);
int* shuffleArray(int arr[], int arrSize);

// main function 
int main(void){

	unsigned int number;
	unsigned int i;
	unsigned int arrSize;
	
	puts(" ");
	puts("Shuffle an array of integers!");
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
	
	
	//shuffling the array and priting the shuffled array
	printArray(shuffleArray(arr, arrSize),arrSize);

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
	puts(" ");
}

// Shuffles all the values inside the array
// Shuffle is done using a nested for loop - both max loop values are randomized based on user input seed
// Values are swapped via index during each shuffle, both of these values are also randomized
int* shuffleArray(int arr[], int arrSize){

	unsigned int i;
	unsigned int k;
	unsigned int seed;
	srand(time(NULL)); // declaration of random using time

	printf("%s", "Enter a shuffle seed (not too big!): ");
	scanf ("%d", &seed);

	unsigned int randomShuffleAmount1 = 1 + (rand() % seed);
	unsigned int randomShuffleAmount2 = 1 + (rand() % seed);


	printf("Random shuffle amount 1: %d\n", randomShuffleAmount1);
	printf("Random shuffle amount 2: %d\n", randomShuffleAmount2);
	printf("Total shuffles to randomize: %d\n", randomShuffleAmount1 + randomShuffleAmount2);
	printf("Here are the randomized index swaps made during shuffling: \n");
	puts(" ");
	
	// if the array has indexes to modify
	if(arrSize > 0){
	    // does the shuffling number of times based on the user input seed
	    for(i = 0; i < randomShuffleAmount1; i++){
		    for(k = 0; k < randomShuffleAmount2; k++){
			    // generate a random index number to swap
			    // then swap it with another random index
			    int randomIndex1 = rand() % arrSize;
			    int randomIndex2 = rand() % arrSize;

			    printf("index [%d]", randomIndex1);
			    printf(" swaps with index [%d]\n", randomIndex2);

			    int temp = arr[randomIndex1];
			    arr[randomIndex1] = arr[randomIndex2];
			    arr[randomIndex2] = temp;
		    }
	    }
	    
	    puts(" ");
	    puts("Values found in array after shuffling: ");
	}
	
	// no array size with modifiable indexes
	else{
	    puts("Values found in array after shuffling: ");
	}

	return arr;
}

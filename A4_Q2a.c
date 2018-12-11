// Author: Tristan Tapson tapsonte

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function prototypes
void printMatrix(int **arr, int dimension);
int sumUpperTriangle(int **arr, int dimension);

// main function 
int main(void){

	unsigned int dimension;
	unsigned int i;
	unsigned int j;
	unsigned int k;
	unsigned int number;
	
	puts(" ");
	puts("Calculate the upper triangle matrix sum of any n x n matrix of integers!");
	printf("%s", "Enter the size (n) of your matrix: ");
	scanf ("%d", &dimension);

	printf("Now creating a %d x %d matrix...\n", dimension, dimension);
	puts(" ");

	// declaration of multidimensional array
	int *arrays[dimension];

	// creates multidimensional array n x n 
	// n is the matrix dimension
	for (i = 0; i < dimension; i++){
		arrays[i] = malloc(dimension * sizeof(int));
	}

	
	// populate the multidimensional array
	for(j = 0; j < dimension; j++){
		for(k = 0; k < dimension; k++){

			printf("Enter row %d column %d's number: ", j, k);
			scanf("%d", &number);
			arrays[j][k] = number;
		}
	}

	// print the matrix
	printMatrix(arrays, dimension);
	printf("%d\n\n", sumUpperTriangle(arrays, dimension));

}

// prints the values found in the matrix
void printMatrix(int **arr, int dimension){

	unsigned int i;
	unsigned int j;

	puts(" ");
	printf("Here is your populated matrix: \n");
	
	for(i = 0; i < dimension; i++){
		for(j = 0; j < dimension; j++){

			// print next row on next line; formatting brackets
			if(j == dimension-1){
				printf("[%d] ", arr[i][j]);
				puts (" ");
			}

			else{
				printf("[%d] ", arr[i][j]);
			}
		}
	}
}

// calculates the sum of the upper triagle of the matrix
int sumUpperTriangle(int **arr, int dimension){

	unsigned int i;
	unsigned int j;
	unsigned int trackScan = 0;
	int sum = 0;

	puts(" ");
	printf("The sum of the upper triangle for this %d x %d matrix is: ", dimension, dimension);

	for(i = 0; i < dimension; i++){
		for(j =0; j < dimension; j++){
			// add to the sum of the upper triangle values
			if(j > trackScan){
				sum += arr[i][j];
			}
		}

		// update the leftRight scan position for summation
		trackScan++;
	}

	return sum;
}








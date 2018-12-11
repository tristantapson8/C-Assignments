//Author: Tristan Tapson tapsonte

/* note: includes both an iterative and recursive approach with timer macros, used to aid the 
	 research and discussion portion of this assignment */

#include <stdio.h>
#include <time.h>

// timer macros
#define startClock(time) clock_t time = clock();
#define stopClock(time) printf("Completion time (%s): %g ms\n", (#time), (double)(clock() - (time)) / (CLOCKS_PER_SEC/1000))

// function prototypes
unsigned long long int print_Fibonacci(unsigned int n);
unsigned long long int fibonacci_Iterative(unsigned int n);
unsigned long long int fibonacci_Recursive(unsigned int n);

// main function
int main(int argc, char *argv[]){

	unsigned int num;

	printf("%s\n", "Please enter a number: ");
	scanf("%u", &num);

	unsigned long long int result = print_Fibonacci(num);
	printf("The %uth Fibonacci number is %u\n", num, result);

	// prints out run time of the iterative fibonacci approach
	startClock(Iterative);
	fibonacci_Iterative(num);
	stopClock(Iterative);

	// prints out run time of the recursive fibonacci approach
	startClock(Recursive);
	fibonacci_Recursive(num);
	stopClock(Recursive);
}

// prints the nth fibonacci number using an iterative approach
unsigned long long int print_Fibonacci(unsigned int n){

	unsigned int current = 0;
	unsigned int next = 1;
	unsigned int add = 1;
	unsigned int i;
	
	printf("Fibonacci (0) is: %u\n", current);
	
	for(i = 0; i < n; i++){
		current = next;
		next = add;
		add = current + next;
		printf("Fibonacci (%u", (i+1));
		printf(") is: %u\n", current);
	}
	return current;
}

// computes the nth fibonacci number using an iterative approach
// print statements are removed as to not affect timer
unsigned long long int fibonacci_Iterative(unsigned int n){

	unsigned int current = 0;
	unsigned int next = 1;
	unsigned int add = 1;
	unsigned int i;
	
	for(i = 0; i < n; i++){
		current = next;
		next = add;
		add = current + next;
	}
	return current;
}

// computes the nth fibonacci number using a recursive approach
// modified from figure 5.15 of the textbook
unsigned long long int fibonacci_Recursive(unsigned int n){
	
	// base cases 
	if (0 == n || 1 == n){
		return n;
	}
	// recursive step
	else {
		return fibonacci_Recursive(n-1) + fibonacci_Recursive(n-2);
	}
}






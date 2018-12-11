// Author: Tristan Tapson tapsonte

#include <stdio.h>
#include <math.h>

// function prototypes
void add(int a, double num1, double num2);
void subtract(int b, double num1, double num2);
void multiply(int c, double num1, double num2);
void divide(int d, double num1, double num2);

// main function
int main(void){

	puts(" ");
	puts("Lets do some basic math calculations between two numbers!");
	puts("Note: all calculations are rounded to two decimal places");
	puts("Option 0: (+) | Option 1: (-) | Option 2: (*) | Option 3: (/)\n");

	// array of function pointers with return type void
	// parameters are the user option as int, and radius as double
	void(*compute[4])(int, double, double) = {add, subtract, multiply, divide};
	size_t choice;
	double num1;
	double num2;

	// initial user input request
	printf("%s", "Enter an option (0, 1, 2, or 3), any other num to end: ");
	scanf("%u", &choice);

	// ignore numbers check if not asking for a calculation
	if(choice >= 0 && choice < 4){
		printf("%s", "Enter number 1: ");
		scanf("%lf", &num1);
		printf("%s", "Enter number 2: ");
		scanf("%lf", &num2);
	}

	// calculation option 0-3 chosen, subsequent user input requests
	while (choice >= 0 && choice < 4){
		(*compute[choice])(choice, num1, num2);
	
		printf("%s", "Enter an option (0, 1, 2, or 3), any other num to end: ");
		scanf("%u", &choice);

		// ignore numbers check if not asking for a calculation
		if(choice >= 0 && choice < 4){
			printf("%s", "Enter number 1: ");
			scanf("%lf", &num1);
			printf("%s", "Enter number 2: ");
			scanf("%lf", &num2);
		}
	}

	puts("No more calculations needed - program end.");
}

// pointer functions 

// calculates and prints the result of num1 + num2
void add(int a, double num1, double num2){
	double result = num1 + num2;
	printf("You entered option %d, so (%.2f + %.2f) is calculated!\n", a, num1, num2);
	printf("The result of the addition is: %.2f \n\n", result);
}

// calculates and prints the result of num1 - num2
void subtract(int b, double num1, double num2){
	double result = num1 - num2;
	printf("You entered option %d, so (%.2f - %.2f) is calculated!\n", b, num1, num2);
	printf("The result of the subtraction is: %.2f \n\n", result);
}

// calculates and prints the result of num1 * num2
void multiply(int c, double num1, double num2){
	double result = num1 * num2;
	printf("You entered option %d, so (%.2f * %.2f) is calculated!\n", c, num1, num2);
	printf("The result of the multiplication is: %.2f \n\n", result);
}

// calculates and prints the result of num1 / num2
void divide(int d, double num1, double num2){
	double result = num1 / num2;
	printf("You entered option %d, so (%.2f / %.2f) is calculated!\n", d, num1, num2);
	printf("The result of the division is: %.2f \n\n", result);
}





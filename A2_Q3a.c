// Author: Tristan Tapson tapsonte

#include <stdio.h>

// function prototypes
int gcd(int num1, int num2);
int getLargest(int num1, int num2);

// main function
int main(int argc, char *argv[]){

	int num1, num2;

	printf("%s\n", "Please enter Integer1: ");
	scanf("%d", &num1);
	printf("%s\n", "Please enter Integer2: ");
	scanf("%d", &num2);

	int result = gcd(num1, num2);
	printf("The greatest common denominator is: %d\n", result);
}

// returns the largest of the two input numbers
int getLargest(int num1, int num2){

	if (num1 > num2){
		return num1;
	}

	else{
		return num2;
	}
}

// returns the gcd of two numbers
int gcd(int num1, int num2){

	int largest = getLargest(num1, num2);
	int gcd, i;
	
	// calculate remainder for both nums to determine common denominator
	// loop upwards so that gcd is always updated by the greatest cmmon denominator
	for(i = 1; i <= largest; i++){
		if(num1%i == 0 && num2%i == 0){
			gcd = i;
		}
	}

	return gcd;
}









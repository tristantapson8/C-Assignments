// Author: Tristan Tapson tapsonte

#include <stdio.h>

// function prototypes
double hypotenuse(double s1, double s2);
double getPower(double x, double y);
double getSqrt(double x);

// main function
int main(int argc, char *argv[]){

	double s1, s2;

	printf("%s\n", "Please enter Side 1: ");
	scanf("%lf", &s1);
	printf("%s\n", "Please enter Side 2: ");
	scanf("%lf", &s2);
	printf("The hypotenuse is: %.2lf\n", hypotenuse(s1, s2));
}

// computes the power of x^y
double getPow(double x, double y){

	int i;
	double result = 1;
	for(i = 0; i < y; i++){
		result *= x;
	}
	return result;
}

// computes the square root of x
double getSqrt(double x){

	int i;
	double result = x / 3;
	for(i = 0; i < 100; i++){
		result = (result + (x / result)) / 2;
	}
	return result;
}

// computes the hypotenuse of a triangle with side lengths s1 and s2
double hypotenuse(double s1, double s2){
	
	printf("Side length 1 is: %lf\n", s1);
	printf("Side length 2 is: %lf\n", s2);
	double result = getSqrt(getPow(s1, 2) + getPow(s2, 2));
	return result;
}

 


// Author: Tristan Tapson tapsonte

#include <stdio.h>
#define PI 3.14159265358979323846

// function prototypes
double getPow(double x, double y);
void getCircumference(int a, double r);
void getArea(int b, double r);
void getVolume(int c, double r);

// main function
int main(void){

	puts(" ");
	puts("Lets do some circle & sphere calculations!");
	puts("Note: all calculations are rounded to two decimal places");
	puts("Option 0: Circumference | Option 1: Area | Option 2: Volume\n");

	// array of function pointers with return type void
	// parameters are the user option as int, and radius as double
	void(*compute[3])(int, double) = {getCircumference, getArea, getVolume};
	size_t choice;
	double radius;

	// initial user input request
	printf("%s", "Enter an option (0, 1, or 2), any other num to end: ");
	scanf("%u", &choice);

	// ignore radius check if not asking for a calculation
	if(choice >= 0 && choice < 3){
		printf("%s", "Enter a radius: ");
		scanf("%lf", &radius);
	}

	// calculation option 0-2 chosen, subsequent user input requests
	while (choice >= 0 && choice < 3){
		(*compute[choice])(choice, radius);
	
		printf("%s", "Enter an option (0, 1, or 2), any other num to end: ");
		scanf("%u", &choice);

		// ignore radius check if not asking for a calculation
		if(choice >= 0 && choice < 3){
			printf("%s", "Enter a radius: ");
			scanf("%lf", &radius);
		}
	}

	puts("No more calculations needed - program end.");
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

// pointer functions 

// calculates and prints circumference based on a given radius
void getCircumference(int a, double r){
	double circumference = 2 * PI * r;
	printf("You entered option %d, so the circumference of a cirlce with radius %.2f is found!\n", a,r);
	printf("The circumference of the circle with radius %.2f is: %.2f \n\n", r, circumference);
}

// calculates and prints area based on a given radius
void getArea(int b, double r){
	double area = PI * (getPow(r,2));
	printf("You entered option %d, so the area of a cirlce with radius %.2f is found!\n", b,r);
	printf("The area of the circle with radius %.2f is: %.2f \n\n", r, area);
}

// calculates and prints volume based on a given radius
void getVolume(int c, double r){
	double volume = (4.0/3.0) * PI * (getPow(r,3));
	printf("You entered option %d, so the volume of a sphere with radius %.2f is found!\n", c,r);
	printf("The volume of the sphere with radius %.2f is: %.2f \n\n", r, volume);
}



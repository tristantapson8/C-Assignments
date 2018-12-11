// Author: Tristan Tapson tapsonte

#include <stdio.h>

// function prototypes
unsigned int add(int x, int y);
unsigned int mult(int x, int y);
unsigned int power(int x, int y);
void displayBits(unsigned int value);

// main function
int main(int argc, char *argv[]){

	int num1, num2;
	
	puts(" ");
	puts("Lets do some bitwise calculations using the shift operator!");
	puts("This program computes (number1 * 2 ^ number2) for integer numbers");
	puts("and outputs the result as an integer and as a unsigned bit representation\n");
	puts("Restrictions: both numbers must be integers; numbers must be an");
	puts("integer > -1 as it will result in a fractional or negative integer");
	puts("bit representation\n");
	printf("%s\n", "Please enter number1: ");
	scanf("%d", &num1);
	printf("%s\n", "Please enter number2: ");
	scanf("%d", &num2);

	while(1){
		// check if you are doing 2^y where y is greater than -1
		if(num1 > -1 && num2 > -1){
			unsigned int result = mult(num1,power(2,num2));
			puts(" ");
			printf("Entered numbers: (%d) & (%d)\n", num1, num2);
			printf("The result of (%d) * 2 ^ (%d) = %d\n", num1, num2, result);
			displayBits(result);
			break;
		}

		// continue to ask for input until both numbers entered are valid
		else{
			puts("Cannot compute for possible fractional/negative results...");
			puts("Try another input set!\n");
			printf("%s\n", "Please enter number 1: ");
			scanf("%d", &num1);
			printf("%s\n", "Please enter number 2: ");
			scanf("%d", &num2);
		}
	}
}

// bitwise addition using the left shift operator (x+y)
unsigned int add(int x, int y){
	int a = y;
	int b = x;
	
	while(y != 0){
		int temp = x & y;
		x = x ^ y;
		y = temp << 1;
	}

	return x;
}

// recursion on bitwise addition to multiply (x*y)
unsigned int mult(int x, int y){
	int temp = 0;
	int count = 0;
	while(count < y ){
		temp += add(x, 0);
		count++;
	}

	return temp;
}

// recursion on bitwise multiplication to power (x^y)
unsigned int power(int x, int y){
	int temp = x;
	int count = 1;

	// x^0 condition
	if(y == 0){
		return 1;
	}

	// x^y
	else{
		while (count < y){
			temp *= mult(x,1);
			count++;
		}

		return temp;
	}
}

// display bits of an unsigned int value
void displayBits(unsigned int value){
	int c;
	unsigned int displayMask = 1 << 31;
	printf("Bit representation of result %u = ", value);

	for(c = 1; c <= 32; ++c){
		putchar(value & displayMask ? '1' : '0');
		value <<= 1;

		if(c % 8 == 0){
			putchar(' ');
		}
	}
	puts(" ");
}


 

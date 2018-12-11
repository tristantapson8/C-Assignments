// Author: Tristan Tapson tapsonte

#include <stdio.h>

// function prototypes
int convertToAscii(char input);
char convertFromAscii(int input);
void unpackCharacters(unsigned int num1);
void displayBits(unsigned int value);

// main function
int main(int argc, char *argv[]){

	unsigned int num1;
	
	puts(" ");
	puts("Lets do some bitwise calculations using the shift operator!");
	puts("This program computes the unpacked characters for an unsigned integer\n");
	printf("%s\n", "Please enter your unsigned integer: ");
	scanf("%d", &num1);
	printf("Entered number: (%d)\n", num1);

	puts(" ");
	printf("(%d) in bits is:\n", num1);
	displayBits(num1);
	
	puts(" ");
	printf("(%d) as two unpacked characters are ", num1);
	unpackCharacters(num1);
}

// converts a character to its ascii table decimal value
int convertToAscii(char input){
	int converted = (int)input;
	return converted;
}

// converts ascii table decimal value to a character 
char convertFromAscii(int input){
	char converted = (char)input;
	return converted;
}

// unpacks an unsigned integer into two character values, and displays their bit representation
void unpackCharacters(unsigned int num1){

	unsigned int mask1 = 65280;
	unsigned int mask2 = 255;
	
	char char1 = convertFromAscii(((num1 & mask1) >> 8));
	char char2 = convertFromAscii((num1 & mask2));
	
	printf("(%c) & (%c)!\n", char1, char2);
	puts("Below are the bit representations of these unpacked characters:");
	displayBits(((num1 & mask1) >> 8));
	displayBits((num1 & mask2));

	puts(" ");
	printf("(%c) in bits as an unsigned integer is: \n", char1);
	int converted1 = convertToAscii(char1);
	displayBits(converted1);

	puts(" ");
	printf("(%c) in bits as an unsigned integer is: \n", char2);
	int converted2 = convertToAscii(char2);
	displayBits(converted2);
}


// display bits of an unsigned int value
void displayBits(unsigned int value){
	int c;
	unsigned int displayMask = 1 << 31;
	printf("%u = ", value);

	for(c = 1; c <= 32; ++c){
		putchar(value & displayMask ? '1' : '0');
		value <<= 1;

		if(c % 8 == 0){
			putchar(' ');
		}
	}
	puts(" ");
}


 

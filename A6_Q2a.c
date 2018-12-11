// Author: Tristan Tapson tapsonte

#include <stdio.h>

// function prototypes
int convertToAscii(char input);
void packCharacters(char char1, char char2);
void displayBits(unsigned int value);

// main function
int main(int argc, char *argv[]){

	char char1;
	char char2;
	
	puts(" ");
	puts("Lets do some bitwise calculations using the shift operator!");
	puts("This program packs two characters and returns the result (in bits)");
	puts("as an unsigned integer");
	puts("Characters are entered on the same line with no spaces (ex: AB)");
	
	printf("%s\n", "Please enter your two characters: ");
	scanf("%c", &char1);
	scanf("%c", &char2);

	
	printf("Entered characters: (%c) & (%c)\n", char1, char2);
	//displayBits(result);
	printf("(%c) converted to Ascii is: %d\n",char1, convertToAscii(char1));
	printf("(%c) converted to Ascii is: %d\n",char2, convertToAscii(char2));
	
	puts(" ");
	printf("(%c) in bits as an unsigned integer is: \n", char1);
	int converted1 = convertToAscii(char1);
	displayBits(converted1);

	puts(" ");
	printf("(%c) in bits as an unsigned integer is: \n", char2);
	int converted2 = convertToAscii(char2);
	displayBits(converted2);

	puts(" ");
	printf("(%c) & (%c) packed in an unsigned integer is: \n", char1, char2);
	packCharacters(char1, char2);
}

// converts a character to its ascii table decimal value
int convertToAscii(char input){
	int converted = (int)input;
	return converted;
}

// packs two characters as an unsigned integer
void packCharacters(char char1, char char2){

	unsigned int converted1 = convertToAscii(char1);
	unsigned int converted2 = convertToAscii(char2);

	// left shift char1 by 8 bits, then bitwise or between shifted char1 and char2
	// display it after
	displayBits(((converted1 << 8) | converted2));
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


 

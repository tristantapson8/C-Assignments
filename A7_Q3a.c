// Author: Tristan Tapson tapsonte
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// function prototypes
int countLinesInFile(char* fileName);
void readFromFile(char* fileName, int lineCount);
void appendToFile(char* fileName, char* formatted, int appendCount);

// main function
int main(void){

	int appendCount; // num of lines to be added
	int lineCount;	// num of lines in the file
	char formatted1[100];	// formtating the input file name as a string of chars

	// file pointer for file1
	char fileName1[100];
	FILE *filePointer1;
	char fileContent1;
	memset(fileName1, 0 , 100);

	puts(" ");
	puts("This program appends additional lines to an existing (.txt) file!");
	printf("Input the file name to be opened: ");
	scanf("%s", fileName1);
	printf("Input the number of lines to be written: ");
	scanf("%d", &appendCount);
	puts(" ");

	// formatting the file name minus ".txt"
	strcpy(formatted1, fileName1);
	int len = strlen(formatted1);
	formatted1[len-4] = '\0';

	// file pointer validation check
	// valid file check for file1
	filePointer1 = fopen(fileName1, "r");
	if(!filePointer1){
		puts("Unable to open file(s), or file(s) not found!");
		puts(" ");
		return 0;
	}

	// print file1 contents before appending 
	printf("The content of the file %s before appending is:\n", fileName1);
	readFromFile(fileName1, countLinesInFile(fileName1));

	// append to file1 based on user input
	appendToFile(fileName1, formatted1, appendCount);

	// print file1 contents after appending
	printf("The content of the file %s after appending is:\n", fileName1);
	readFromFile(fileName1, countLinesInFile(fileName1));

	return 0;
}

// reads the contents of a text file, and prints it as a string
void readFromFile(char* fileName, int lineCount){

	int i = 0;
	FILE* filePointer = fopen(fileName, "r");
	char singleLine[100];

	// until end of file is reached
	while(!feof(filePointer)){
		if(i < lineCount){
			// print a line 
			fgets(singleLine, 100, filePointer);
			printf("%s", singleLine);
			// update current line count
			i++;
		}

		// otherwise no more new lines found
		else{
			puts(" ");
			break;
		}
	}
	
	fclose(filePointer);
}

// appends lines to text file
void appendToFile(char* fileName, char* formatted, int appendCount){

	int i;
	int lineCount = countLinesInFile(fileName) + 1;
	FILE* filePointer = fopen(fileName, "a");
	puts("The lines to be added are: ");

	// append to file user specifed amount of new lines
	for(i = 0; i < appendCount; i++){

		char buffer[100];
		memset(&buffer, 0, sizeof(buffer));
		sprintf(buffer, "%d", lineCount);
		printf("%s line %d\n", formatted, lineCount);

		// append content, in the form "<filename> line <line count>"
		fprintf(filePointer, formatted);
		fprintf(filePointer, " line ");
		fprintf(filePointer, buffer);
		fprintf(filePointer, "\n");

		// update new line count
		lineCount++;
		
	}

	puts(" ");
	fclose(filePointer);
}


// counts the number of lines in an input file
int countLinesInFile(char* fileName){
	
	int fileContent; 
	int lineCount = 0;
	FILE* filePointer = fopen(fileName, "r");

	// update line count every time a new line character is reached, until end of file found
	do{
		// scan done on each character
		fileContent = fgetc(filePointer);
		if(fileContent == '\n'){
			lineCount++;
		}
	}
	while(fileContent != EOF);

	// base cases, 1 or less lines in file
	if(fileContent != '\n' && lineCount == 0){

		// empty text file 
		if(lineCount < 1){
			lineCount == 0;
		}

		// text file with a single line
		else{
			lineCount == 1;
		}
	}

	fclose(filePointer);
	return lineCount;
}





// Author: Tristan Tapson tapsonte
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// main function
int main(void){

	// merge completion pseudo-booleans
	// tracks when contents have been merged into the merge file
	int bool_merge1 = 0;
	int bool_merge2 = 0;

	// file pointer for file1
	char fileName1[100];
	FILE *filePointer1;
	char fileContent1;
	memset(fileName1, 0 , 100);

	// file pointer for file2
	char fileName2[100];
	FILE *filePointer2;
	char fileContent2;
	memset(fileName2, 0 , 100);

	// file pointer for merge file
	char mergeFileName[100];
	FILE *mergeFilePointer ;
	char mergeFileContent;
	memset(mergeFileName, 0 , 100);

	// user input sequence
	puts(" ");
	puts("This program appends the contents of two (.txt) files to another (.txt) file!");
	printf("Input the 1st file name: ");
	scanf("%s", fileName1);
	printf("Input the 2nd file name: ");
	scanf("%s", fileName2);
	printf("Input the new file name where to merge the above two files: ");
	scanf("%s", mergeFileName);
	puts(" ");

	// file pointer validation checks

	// valid file check for file1
	filePointer1 = fopen(fileName1, "r");
	if(!filePointer1){
		puts("Unable to open file(s), or file(s) not found!");
		return 0;
	}

	// valid file check for file2
	filePointer2 = fopen(fileName2, "r");
	if(!filePointer2){
		puts("Unable to open file(s), or file(s) not found!");
		return 0;
	}

	// valid file check for merge file
	mergeFilePointer = fopen(mergeFileName, "w");
	if(!mergeFilePointer){
		puts("Unable to open file(s), or file(s) not found!");
		
		// close pointers to files if nothing valid to merge to
		fclose(filePointer1);
		fclose(filePointer2);
		fclose(mergeFilePointer);
		return 0;
	}

	// print file 1 contents, and append it to merge file
	if(filePointer1){
		printf("The content of the file %s is:\n", fileName1);
		while ((fileContent1 = getc(filePointer1)) != EOF){
			putchar(fileContent1);
			fputc(fileContent1, mergeFilePointer);
		
		}
		puts(" ");
		fclose(filePointer1);
		bool_merge1++;
	}

	// print file 2 contents, and append it to merge file
	if(filePointer2){
		printf("The content of the file %s is:\n", fileName2);
		while ((fileContent2 = getc(filePointer2)) != EOF){
			putchar(fileContent2);
			fputc(fileContent2, mergeFilePointer);
		
		}
		puts(" ");
		fclose(filePointer2);
		bool_merge2++;
	}

	// close merge file pointer after writing to it
	fclose(mergeFilePointer);

	// once file1 and file2 are closed 
	if(bool_merge1 == 1 && bool_merge2 == 1){
		
		// read the contents of merge file after it has been written to
		mergeFilePointer = fopen(mergeFileName, "r");
		printf("The two files merged into %s file successfully...!\n", mergeFileName);

		// print the modified merge file contents
		if(mergeFilePointer){
			printf("Here is the content of the merge file %s:\n", mergeFileName);
			while ((mergeFileContent = getc(mergeFilePointer)) != EOF){
				putchar(mergeFileContent);
			}
		}
		puts(" ");
	}
}


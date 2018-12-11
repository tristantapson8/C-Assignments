//Author: Tristan Tapson tapsonte

/*note: This simulation for towers of hanoi doesnt quite work, (works for <= 3 disks perfectly) with the
	logic found on wikipedia for iteratve approach to towers of hanoi, however doesnt work for > 3 
	number of disks? might be an off by 1 error somewhere in one of the array indexing, however 
	the iterative code for this is very complicated. The logic followed was:

	Number disks 1 through n
		- if n is odd, the first move is from pegA to pegC
		- if n is even, the first move is from pegA to pegB
	Then do constraints:
		- no odd disk can be placed ontop of an odd disk
		- no even disk can be placed ontop of an even disk
		- if there are two possible pegs, place the disk on the non-empty peg
		- never move a disk twice in succession

	All iterations and logic checks, as well as a visual representation of the towers and disks
	are printed out neatly via print statements, and the sequencing is printed once the towers 
	have been completed; if it fails to complete after the maximum possible number of moves, the
	program is stopped, and the sequencing (incorrect) is still printed out anyways to help with 
	debugging	
*/ 

/* note2: since it isnt fully finished, there is still alot of similar code that can be simplified 
	  down further present in this program... 
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <errno.h>

// timer macros
#define startClock(time) clock_t time = clock();
#define stopClock(time) printf("Completion time (%s): %g ms\n", (#time), (double)(clock() - (time)) / (CLOCKS_PER_SEC/1000))

// function prototypes
int getPow(int x, int y);
int whichPeg(int disks,int val, int arr1[], int arr2[], int arr3[]);
bool isOnPeg(int val, int *arr, int size);
void printStacks(int num, int arr1[], int arr2[], int arr3[]);
int getIndex(int val, int *arr, int size);
int getTop(int *arr, int size);
void toBottom(int val, int *arr, int size);
int fromTop(int val, int *arr, int size);
int checkParity(int num);
int compareParity(int num1, int num2);
void hanoi_Iterative(int disks, int arr1[], int arr2[], int arr3[]);

// main function
int main(int argc, char *argv[]){

	int num;
	int *arr1;
	int *arr2;
	int *arr3;
	int i;

	printf("%s\n", "Please enter number of disk(s): ");
	scanf("%d", &num);
	
	arr1 = (int *) malloc(sizeof(int)* num);
	arr2 = (int *) malloc(sizeof(int)* num);
	arr3 = (int *) malloc(sizeof(int)* num);

	// populate arrays (pegs) with disk sizes
	// 0 means no disk of a size is on that peg slot
	for(i = 0; i < num; i++){
		arr1[i] = i+1;
		arr2[i] = 0;
		arr3[i] = 0;
	}

	// iterative simulation of towers of hanoi
	hanoi_Iterative(num, arr1, arr2, arr3);
	
}

// computes the power of x^y
int getPow(int x, int y){

	int i;
	int result = 1;
	for(i = 0; i < y; i++){
		result *= x;
	}
	return result;
}


// aux function for whichPeg
bool isOnPeg(int val, int *arr, int size){
	int i;
	// if value in array
	for(i = 0; i < size; i++){
		if (arr[i] == val){
			return true;
		}
	}
	// else
	return false;
}

// check to see which peg a disk is on
int whichPeg(int disks, int val, int arr1[], int arr2[], int arr3[]){
	// is on pegA
	if (isOnPeg(val, arr1, disks) == true){
		return 1;
	}
	// is on pegB
	else if(isOnPeg(val, arr2, disks) == true){
		return 2;
	}
	// is on pegC
	else {
		return 3;
	}
}

// testing purposes, prints a visual to see what is happening after each iteration
void printStacks(int num, int arr1[], int arr2[], int arr3[]){
	int i;
	for(i = 0; i < num; i++){
		printf("PEG A: %d", arr1[i]);
		printf(" PEG B: %d", arr2[i]);
		printf(" PEG C: %d\n", arr3[i]);
		
	}

	printf("\n");

}


// get index of element
int getIndex(int val, int *arr, int size){
	int i;
	// if value in array
	for(i = 0; i < size; i++){
		if (arr[i] == val){
			return i;
			break;
		}
	}
}

// get value from top of array
int getTop(int *arr, int size){
	int i;
	// if value in array
	for(i = 0; i < size; i++){
		if (arr[i] !=0 ){
			return arr[i];
			break;
		}
	}
	// otherwise empty
	return 0;
}

// push to bottom of array
void toBottom(int val, int *arr, int size){
	int i;
	// if empty (denoted by 0's), populate peg
	for(i = size-1; i > -1; i--){
		if (arr[i] == 0 ){
			arr[i] = val;
			break;
		}
	}
}

// pop from top of array
int fromTop(int val, int *arr, int size){
	int i;
	// move disk off of peg
	for(i = 0; i < size; i++){
		if (arr[i] == val){
			// if nothing is 'ontop' of a disk
			if(i > 0 && arr[i-1] == 0){
				arr[i] = 0;
				puts("Nothing ontop of disk, can pop off peg!");
				return 1;
				break;
			}
			// disk is at the top
			else if(i == 0){
				puts ("Disk at the top, can pop off peg!");
				arr[i] = 0;	
				return 1;
				break;
			}
			else{
				puts("Cant pop off peg, something ontop of disk!");
				return 0;
				break;
			}
		}
	}
}

// checks parity
int checkParity(int num){
	// return 0 for even
	if (num%2 == 0){
		return 0;
	}
	// return 1 for odd
	else{
		return 1;
	}
}

// compares parity
int compareParity(int num1, int num2){
	// false if numbers are both even or both odd
	if (checkParity(num1) == checkParity(num2)){
		return 0;
	}
	// true otherwise
	else{
		return 1;
	}
}

// iterative towers of hanoi
void hanoi_Iterative(int disks, int arr1[], int arr2[], int arr3[]){

	puts("---------------- TOWERS OF HANOI SIMULATION --------------");
	
	int moveCounter = 0;
	int max = getPow(2,disks);
	int i;
	int j;
	int k,m;
	int l = 2;

	// parity counters, can be any nums, as long as odd is an odd num, and even is an even num
	int odd = 3;
	int even = 4;
	
	int topA, topB, topC;
	int sizeA = disks-2;
	int sizeB = 1;
	int sizeC = 1;

	// array to hold string of disk movement sequenncing
	const char *a[(max*disks)];


	// even number of disks disks 
	if(disks % 2 == 0){
		topA = odd;
		topB = even;
		topC = odd;

		arr1[0]= 0;
		arr1[1] = 0;

		arr2[disks-1] = 1;
		arr3[disks-1] = 2;
	
		a[0] = "1 -> 2";
		a[1] = "1 -> 3";

		puts("Even disk number entered, preload accordingly...");
	}
	
	// odd number of disks
	else {
		topA = odd;
		topB = odd;
		topC = even;

		arr1[0]= 0;
		arr1[1] = 0;

		arr2[disks-1] = 2;
		arr3[disks-1] = 1;

		a[0] = "1 -> 3";
		a[1] = "1 -> 2";

		puts("Odd disk number entered, preload accordingly...");
	}
	

	// max moves iteration
	for(i = 1; i < max; i++){
		for(j = 1; j < disks+1;j++){
		
			moveCounter++;

			puts(" ");
			printf("-------- Hanoi Iteration: %d -------- ", moveCounter);
			puts(" ");
			printStacks(disks, arr1, arr2, arr3);
			printf("Total disks on PEG 1: %d\n", sizeA);
			printf("Total disks on PEG 2: %d\n", sizeB);
			printf("Total disks on PEG 3: %d\n", sizeC);
			puts(" ");
			puts("Computing logic for disk movements...");
			puts(" ");

			// determine which peg its on currently
			int det = whichPeg(disks, j, arr1, arr2, arr3);

			// double valid move counters
			int isValidAB = 0;
			int isValidAC = 0;
			int isValidBA = 0;
			int isValidBC = 0;
			int isValidCA = 0;
			int isValidCB = 0;

			int isValidA = 0;
			int isValidB = 0;
			int isValidC = 0;

			// printing mem usage
			struct rusage r_usage;
			getrusage(RUSAGE_SELF, &r_usage);	
			

	
			// skip the first two checks as odd/even starts are preloaded into the arrays
			if(moveCounter > 2){
			
			// towers of hanoi simulation completed sucessfully?
			if((sizeC == disks || sizeB == disks) && moveCounter < ((max-1)*disks)){
				puts("Simulation Completed Sucessfully!");
				puts("Sequencing found below: \n");
				for(k = 0; k < l; k++){
					printf("%s\n", a[k]);
				}

				puts(" ");
				printf("Memory usage: %ld kilobytes", r_usage.ru_maxrss);
				break;
			}

			// towers of hanoi simulation unsucessfull
			else{
				if(moveCounter >=  ((max-1)*disks)){
					puts("Simulation Completed Unsucessfully...");
					puts("Sequencing (Incorrect) printed anyways for debugging: \n");
					for(m = 0; m < l; m++){
						printf("%s\n", a[m]);
					}

					puts(" ");
					printf("Memory usage: %ld kilobytes", r_usage.ru_maxrss);
					break;
				}
			
			}

			printf("Checking disk: (%d)",j);
			printf("\n");


			// if on a, check if b c valid, move
			if (det == 1){
				puts ("Disk is on peg A");
				// A check
				// valid odd on even
				int AB = compareParity(getTop(arr1, disks),getTop(arr2, disks));
				printf("Parity check AB: %d\n", AB);

				if((compareParity(getTop(arr1, disks),getTop(arr2, disks)) == 1 || getTop(arr2,disks) == 0) && (getTop(arr2, disks) > j || getTop(arr2, disks) == 0)){

					// valid sizing (bottom disk is bigger than current disk)
					puts("Valid A to B odd even move");
					printf("Check top of B: %d\n", getTop(arr2, disks));
					puts("Bot disk bigger (or 0) so move is valid");
				
					// AB move valid
					if(fromTop(j, arr1, disks) > 0){
						isValidA++;
						isValidAB++;
					}

					else{
						// do nothing
						puts ("Disk is too big!");
						puts ("A to B failed");
					}
				}

					
				if (isValidA >= 0){	
					if(1>0){
						puts("Now check A to C as well");
						// valid odd on even

						int AC = compareParity(getTop(arr1, disks),getTop(arr3, disks));
						printf("Parity check AC: %d\n", AC);
					
						// valid odd on even
				 		if((AC == 1 || getTop(arr3, disks) == 0) && arr3[0] == 0){
							puts("Valid A to C odd even move");
		
						// valid sizing (bottom disk is bigger than current disk)

							printf("Check top of C: %d\n", getTop(arr3, disks));
							if(getTop(arr3, disks) > j || getTop(arr3, disks) == 0){
								puts("Bot disk bigger (or 0) so valid move");

								// AC move valid
								if(fromTop(j, arr1, disks) > 0){
									isValidA ++;
									isValidAC++;
								}
							}

							// no valid move
							else{
								// do nothing
								puts ("Disk is too big!");
								puts ("A to C failed");
							}
						}
					}

					// valid conditions
					printf("Total valid A moves on iteration: %d\n", isValidA);
					printf("Valid A to B moves on iteration: %d\n", isValidAB);
					printf("Valid A to C moves on iteration: %d\n", isValidAC);

					if(isValidA > 1 ){
						puts("There are 2 possible moves from A!");
						// place on the non-empty disc
						if(sizeB == 0){
							puts("B empty, C is not, move to C instead");
							// move disk from a to c
							printf("Move disk (%d) from peg %d -> peg 3\n", j, det);
							a[l] = "1 -> 3" ; l++;
							toBottom(j, arr3, disks);
							topA +=1;
							topC +=1;
							sizeA-=1;
							sizeC +=1;
						
						}

						else {
							puts("C empty, B is not, move to B instead");
							// move disk from a to b
							printf("Move disk (%d) from peg %d -> peg 2\n", j, det);
							a[l] = "1 -> 2"; l++;
							toBottom(j, arr2, disks);
							topA +=1;
							topB +=1;
							sizeA -=1;
							sizeB +=1;
						}
					}

					// one valid move, but which one?
					else if(isValidA == 1){
						if(isValidAB == 1){
						// move disk from a to b 
							printf("Move disk (%d) from peg %d -> peg 2\n", j, det);
							a[l] =  "1 -> 2" ; l++;
							toBottom(j, arr2, disks);
							topA +=1;
							topB +=1;
							sizeA-=1;
							sizeB +=1;
						
						}
					
						else{
							// move disk from a to c
							printf("Move disk (%d) from peg %d -> peg 3\n", j, det);
							a[l] = "1 -> 3" ; l++;
							toBottom(j, arr3, disks);
							topA +=1;
							topC +=1;
							sizeA-=1;
							sizeC +=1;

						}
					}

					else{
						puts("No valid move(s) for this disk\n");
					}
				}	
			} // done a to (b,c) check
	
			// if on b, check if a c valid, move
			if (det == 2){
				puts ("Disk is on peg B");
				// A check
				// valid odd on even
				int BA = compareParity(getTop(arr2, disks),getTop(arr1, disks));
				printf("Parity check BA: %d\n", BA);

				if((compareParity(getTop(arr2, disks),getTop(arr1, disks)) == 1 || getTop(arr1,disks) == 0) && 
					
					(getTop(arr1, disks) > j || getTop(arr1, disks) == 0)){

					// valid sizing (bottom disk is bigger than current disk)
					puts("Valid B to A odd even move");
					printf("Check top of A: %d\n", getTop(arr1, disks));


					puts("Bot disk bigger (or 0) so move");
				
					// BA move valid
					if(fromTop(j, arr2, disks) >0){
						isValidB++;
						isValidBA++;
					}

					else{
						// do nothing
						puts ("Disk is too big!");
						puts ("B to A failed");
					}
				}

				
				if (isValidB >= 0) {	
					if(1>0){
						puts("Now check B to C");
						// valid odd on even
						// first possible move a to b fails

						int BC = compareParity(getTop(arr2, disks),getTop(arr3, disks));
						printf("Parity check BC: %d\n", BC);

				 		
					
						// valid odd on even and can place ontop
				 		if((BC == 1 || getTop(arr3, disks) == 0) && arr3[0] == 0){
							puts("Valid b to C odd even move");
							// valid sizing (bottom disk is bigger than current disk)
							printf("Check top of C: %d\n", getTop(arr3, disks));
							if(getTop(arr3, disks) > j || getTop(arr3, disks) == 0){
								puts("Bot bigger (or 0) so move");
								// BC move valid
								if(fromTop(j, arr2, disks) > 0){
							
									isValidB++;
									isValidBC++;
								}
							}

							// no valid move
							else{
								// do nothing
								puts ("Disk is too big!");
								puts ("B to C also failed");
							}
						}
					}

					// valid conditions
					printf("Total valid B moves on iteration: %d\n", isValidB);
					printf("Valid B to A moves on iteration: %d\n", isValidBA);
					printf("Valid B to C moves on iteration: %d\n", isValidBC);

					if(isValidB > 1 ){
						puts("There are 2 possible moves from B!");
						// place on the non-empty disc
						if(sizeA == 0){
							puts("A empty, C is not, move to C instead");
							// move disk from b to c
							printf("Move disk (%d) from peg %d -> peg 3\n", j, det);
							a[l] = "2 -> 3" ; l++;
							toBottom(j, arr3, disks);
							topB +=1;
							topC +=1;
							sizeB-=1;
							sizeC +=1;
						}

						else {
							puts("C empty, A is not, move to A instead");
							// move disk from b to a
							printf("Move disk (%d) from peg %d -> peg 1\n", j, det);
							a[l] = "2 -> 1" ; l++;
							toBottom(j, arr2, disks);
							topA +=1;
							topB +=1;
							sizeB -=1;
							sizeA +=1;
						}
					}

					// one valid move only, 
					else if(isValidB == 1){
						if(isValidBC == 1){
						// move disk from b to c
							printf("Move disk (%d) from peg %d -> peg 3\n", j, det);
							a[l] = "2 -> 3"; l++;
							toBottom(j, arr3, disks);
							topB +=1;
							topC +=1;
							sizeB-=1;
							sizeC +=1;
						}

						else{
							// move disk from b to a
							printf("Move disk (%d) from peg %d -> peg 1\n", j, det);
							a[l] = "2 -> 1" ; l++;
							toBottom(j, arr1, disks);
							topB +=1;
							topA +=1;
							sizeB-=1;
							sizeA +=1;
						}
					}

					else{
						puts("No valid move(s) for this disk");
					}
			

				}

					
			} // done b to (a,c) check 

			// if on c, check if b a valid, move
			if (det == 3){
				puts ("Disk is on peg C");
				// B check
				// valid odd on even
				int CB = compareParity(getTop(arr3, disks),getTop(arr2, disks));
				printf("Parity check CB: %d\n", CB);

				if((compareParity(getTop(arr3, disks),getTop(arr2, disks)) == 1 || getTop(arr2,disks) == 0) && 
					
					(getTop(arr2, disks) > j || getTop(arr2, disks) == 0)){

					// valid sizing (bottom disk is bigger than current disk)
					puts("Valid C to B odd even move");
					printf("Check top of B: %d\n", getTop(arr2, disks));
					puts("Bot disk bigger (or 0) so move");
						
					// CB move valid
					if(fromTop(j, arr3, disks) > 0){
						isValidC++;
						isValidCB++;
					}

					else{
						// do nothing
						puts ("Disk is too big!");
						puts ("C to B failed");
					}
				}

					
				if(isValidC >=0) {	
					if(1>0){
						puts("Now check C to A");
						// valid odd on even
						// first possible move a to b fails

						int CA = compareParity(getTop(arr3, disks),getTop(arr1, disks));
						printf("Parity check CA: %d\n", CA);

						// valid odd on even
				 		if((CA == 1 || getTop(arr1, disks) == 0)&& arr1[0] == 0){
							puts("Valid c to 1 odd even move");
							// valid sizing (bottom disk is bigger than current disk)

							printf("Check top of A: %d\n", getTop(arr1, disks));
							if(getTop(arr1, disks) > j || getTop(arr1, disks) == 0){
								puts("Bot disk bigger (or 0) so move");

								// CA move valid
								if(fromTop(j, arr3, disks) > 0){
									isValidC++;
									isValidCA++;
								}
							}

							// no valid move
							else{
								// do nothing
								puts ("Disk is too big!");
								puts ("C to A also failed");
							}
						}
					}

					// valid conditions
					printf("Total valid C moves on iteration: %d\n", isValidC);
					printf("Valid C to B moves on iteration: %d\n", isValidCB);
					printf("Valid C to A moves on iteration: %d\n", isValidCA);

					if(isValidC > 1 ){
						puts("There are 2 possible moves from A!");
						// place on the non-empty disc
						if(sizeA == 0){
							puts("A empty, B is not, move to B instead");
							// move disk from c to b
							printf("Move disk (%d) from peg %d -> peg 2\n", j, det);
							a[l] = "3 -> 2";  l++;
							toBottom(j, arr2, disks);
							topB +=1;
							topC +=1;
							sizeC-=1;
							sizeB +=1;
						}

						else {
							puts("B empty, A is not, move to A instead");
							// move disk from c to a
							printf("Move disk (%d) from peg %d -> peg 1\n", j, det);
							a[l] = "3 -> 1"; l++;
							toBottom(j, arr1, disks);
							topC +=1;
							topB +=1;
							sizeC -=1;
							sizeB +=1;
						}
					}

					// one valid move only, 
					else if(isValidC == 1){
						if(isValidCB == 1){
							// move disk from c to b
							printf("Move disk (%d) from peg %d -> peg 2\n", j, det);
							a[l] = "3 -> 2"; l++;
							toBottom(j, arr2, disks);
							topB +=1;
							topC +=1;
							sizeC-=1;
							sizeB +=1;
						}

						else{
							// move disk from c to a
							printf("Move disk (%d) from peg %d -> peg 1\n", j, det);
							a[l] = "3 -> 1"; l++;
							toBottom(j, arr1, disks);
							topA +=1;
							topC +=1;
							sizeC-=1;
							sizeA +=1;
						}
					}

					else{
						puts("No valid move(s) for this disk");
	
						}
					
					} // done c to (b,a) check 
				}
			
			}// done a/b/c checks
		}
	}	
}





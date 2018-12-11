// Author: Tristan Tapson tapsonte

#include <stdio.h>
#include <time.h>
#include <sys/resource.h>

// function prototypes
void hanoi_Recursive(int disks, int peg1, int peg2, int peg3);

// main function
int main(int argc, char *argv[]){

	int num;

	// printing mem usage
	struct rusage r_usage;
	getrusage(RUSAGE_SELF, &r_usage);
	
	printf("%s\n", "Please enter number of disk(s): ");
	scanf("%d", &num);
	
	hanoi_Recursive(num, 1, 2, 3);

	puts(" ");
	printf("Memory usage: %ld kilobytes", r_usage.ru_maxrss);

	
}

// towers of hanoi using a recursive approach
void hanoi_Recursive(int disks, int peg1, int peg2, int peg3){
	
	int n = disks;
	int p1 = peg1;
	int p2 = peg2;
	int p3 = peg3;

	// base case
	if(n == 1){
		printf("%d -> %d\n", p1, p2);
		return;
	}

	// recursive steps
	hanoi_Recursive(n-1, p1, p3, p2);
	printf("%d -> %d\n", p1, p2);
	hanoi_Recursive(n-1, p3, p2, p1);

}






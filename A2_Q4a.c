// Author: Tristan Tapson tapsonte

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
int rollDice(void);
void chatter(int result);
int wager(void);

enum Status {CONTINUE, WON, LOST};

int bankBalance = 1000;

int rollDice(void);

int main(void){
	
	int sum = wager();

}

// function to roll a random sum from two die
int rollDice(void){
	int die1 = 1 + (rand() % 6);
	int die2 = 1 + (rand() % 6);

	printf("Player rolled %d + %d = %d\n", die1, die2, die1 + die2);
	return die1 + die2;
}

// function to display random messages after a game is either won or lost
void chatter(int result){
	
	int message = 1 + (rand() % 2);
	
	switch(result){

		// randomized win message displayed
		case 1:
			if (message == 1){
				puts("Aw cmon, take a chance!\n");
			}
			else{
				puts("You're up big. Now's the time to cash in your chips!\n");
			}
			break;
		
		// randomized loss message displayed
		case 0:
			if (message == 1){
				puts("Aw cmon, take a chance!\n");
			}
			else{
				puts("Oh, you're going for broke, huh?\n");
			}
			break;
	}
}

// craps game simulator, allows the player to place a wager
int wager(void){

	srand(time(NULL));
	int myPoint;
	enum Status gameStatus;
	int wager;
	int sum;

	// continue playing until bank balance is 0
	while(bankBalance != 0){
		printf("%s", "Enter a wager: ");
		scanf("%d", &wager);

		// ask for another number if wager is greater than the bank balance
		if(wager > bankBalance ){
			puts("Insufficient funds! Re-enter a valid wager");
		}
                
		// if number entered is valid, commence the craps game
		else {
			puts("Wager is valid. Commencing craps game...");
			sum = rollDice();	
			
			switch(sum){

				case 7:
				case 11:
					gameStatus = WON;
					break;
		
				case 2:
				case 3:
				case 12:
					gameStatus = LOST;
					break;

				default:
					gameStatus = CONTINUE;
					myPoint = sum;
					printf("Point is %d\n", myPoint);
					break;
			}

			while(CONTINUE == gameStatus){
				sum = rollDice();

				if(sum == myPoint){
					gameStatus = WON;
				}
				else{
					if(7 == sum){
						gameStatus = LOST;
					}
				}
			}
	
			// update and display bank balance after a win
			if(WON == gameStatus){
				bankBalance += wager;
				puts("Player wins");
				printf("Bank balance is: %d\n", bankBalance);
				// display random win "chatter"
				chatter(1);
			}

			// update and display bank balance after a loss
			else{
				bankBalance -= wager;
				puts("Player loses");
				printf("Bank balance is: %d\n", bankBalance);

				// once no more funds are available
				if(bankBalance == 0){
					puts("Sorry. You busted!");
				}
				else{
					// display random loss "chatter"
					chatter(0);
				}
			}
		}
	}

	return 0;
}














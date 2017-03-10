#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "common/io.h"

#define ROCK 1
#define PAPER 2
#define SCISSOR 3

void getUserPick(int *user_pick);
int getRandomPick();
int evalPicks(int user_pick, int comp_pick);

void printPick(int pick);
void printUserPick(int user_pick);
void printCompPick(int comp_pick);

int main(int argc, char **argv) {

	int user_score = 0, comp_score = 0;
	int exit = 0;
	int user_pick, comp_pick;
	int status;

	time_t t;
	srand((unsigned) time(&t));

	while(!exit) {
		getUserPick(&user_pick);

		if(user_pick == 4) {
			exit = 1;
			if(user_score > comp_score) {
				printf("You win!\n");
			} else if(user_score < comp_score) {
				printf("You lose!\n");
			} else {
				printf("It's a draw!\n");
			}
			break;
		}

		comp_pick = getRandomPick();

		printUserPick(user_pick);
		printCompPick(comp_pick);

		status = evalPicks(user_pick, comp_pick);

		printf("This round - ");

		switch(status) {
			case 2:
				printf("Draw!\n");
				break;
			case 1:
				printf("Win!\n");
				user_score++;
				break;
			case 0:
				printf("Lose!\n");
				comp_score++;
				break;
			case -1:
				printf("Invalid Input!\n");
				break;
		}
	}
}

void getUserPick(int *user_pick) {
	printf("1 - Rock\n");
	printf("2 - Paper\n");
	printf("3 - Scissor\n");
	printf("4 - Quit\n");
	printf("Enter your pick: ");
	*user_pick = getch() - '0';
	printf("\n");
}

int getRandomPick() {
	float rock_pick = rand() / (float)RAND_MAX;
	float paper_pick = rand() / (float)RAND_MAX;
	float scissor_pick = rand() / (float)RAND_MAX;

	float m = rock_pick > paper_pick ? rock_pick : paper_pick;
	float n = scissor_pick > m ? scissor_pick : m;

	if(n == rock_pick) return ROCK;
	if(n == paper_pick) return PAPER;
	if(n == scissor_pick) return SCISSOR;
	return -1;
}

int evalPicks(int user_pick, int comp_pick) {

	/*if(user_pick != ROCK && user_pick != PAPER && user_pick != SCISSOR && comp_pick != ROCK && comp_pick != PAPER && comp_pick != SCISSOR)*/
		/*return -1;*/

	if(user_pick == comp_pick) return 2;

	if(user_pick == ROCK) {
		if(comp_pick == PAPER) {
			return 0;
		} else if(comp_pick == SCISSOR) {
			return 1;
		}
	} else if(user_pick == PAPER) {
		if(comp_pick == ROCK) {
			return 1;
		} else if(comp_pick == SCISSOR) {
			return 0;
		}
	} else if(user_pick == SCISSOR) {
		if(comp_pick == ROCK) {
			return 0;
		} else if(comp_pick == PAPER) {
			return 1;
		}
	}

	return -1;
}

int getRandomNumber(int max, int min) {
	return  (int)((rand() / (float)RAND_MAX) * (max - min - 1)) + min + 1;
}

void printPick(int pick) {
	if(pick == ROCK) {
		printf("Rock");
	} else if(pick == PAPER) {
		printf("Paper");
	} else if(pick == SCISSOR) {
		printf("Scissor");
	} else {
		printf("Invalid!");
	}
}

void printUserPick(int user_pick) {
	printf("Your pick was ");
	printPick(user_pick);
	printf("\n");
}

void printCompPick(int comp_pick) {
	printf("Computer's pick was ");
	printPick(comp_pick);
	printf("\n");
}

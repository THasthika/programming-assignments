#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define INIT_MAX_GUESS 1000000
#define INIT_MIN_GUESS -1000000

int getRandomNumber(int max, int min);

int main(int argc, char **argv) {

	int exit = 0;

	time_t t;

	srand((unsigned) time(&t));

	int guess, guessMax, guessMin, i;

	printf("Think of a number and press enter: ");
	scanf("%c", &i);

	guessMax = INIT_MAX_GUESS;
	guessMin = INIT_MIN_GUESS;
	guess = getRandomNumber(guessMax, guessMin);

	while(!exit) {
		printf("Was it %d?\n", guess);
		printf("Press 1 if it was High\n");
		printf("Press 2 if it was Low\n");
		printf("Press 3 if it was Correct\n");
		printf("Press 4 to exit\n");
		scanf("%d", &i);

		switch(i) {
			case 1:
				guessMax = guess;
				if(guessMax - guessMin < 2)
					guessMin -= 100;
				break;
			case 2:
				guessMin = guess;
				if(guessMax - guessMin < 2)
					guessMax += 100;
				break;
			case 3:
				printf("Found it!\n");
				exit = 1;
				break;
			case 4:
				exit = 1;
				break;
			default:
				printf("Invalid Input!\n");
				break;
		}

		guess = getRandomNumber(guessMax, guessMin);
	}

}

int getRandomNumber(int max, int min) {
	return  (int)((rand() / (float)RAND_MAX) * (max - min - 1)) + min + 1;
}

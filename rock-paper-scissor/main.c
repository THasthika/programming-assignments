#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROCK 1
#define PAPER 2
#define SCISSOR 3

#ifdef __unix__
#include <termios.h>
#elif defined(_WIN32) || defined(WIN32)
#include <conio.h>
#endif

#ifdef __unix__
static struct termios old, new;

void initTermios(int echo);
void resetTermios();
char getch_(int echo);
char getch();
char getche();
#endif

int getRandomNumber(int max, int min);
void getUserInput(int *u);
int evalOutput(int u, int c);

int main(int argc, char **argv) {

	/*char c;*/
	/*printf("(getche example) please type a letter: ");*/
          /*c = getche();*/
          /*printf("\nYou typed: %c\n", c);*/
          /*printf("(getch example) please type a letter...");*/
          /*c = getch();*/
          /*printf("\nYou typed: %c\n", c);*/
          /*return 0;*/

	int exit = 0;

	/*time_t t;*/

	/*srand((unsigned) time(&t));*/

	/*int guess, guessMax, guessMin, i;*/

	/*printf("Think of a number and press enter: ");*/
	/*scanf("%c", &i);*/

	/*guessMax = INIT_MAX_GUESS;*/
	/*guessMin = INIT_MIN_GUESS;*/
	/*guess = getRandomNumber(guessMax, guessMin);*/

	/*while(!exit) {*/
		/*printf("Was it %d?\n", guess);*/
		/*printf("Press 1 if it was High\n");*/
		/*printf("Press 2 if it was Low\n");*/
		/*printf("Press 3 if it was Correct\n");*/
		/*printf("Press 4 to exit\n");*/
		/*scanf("%d", &i);*/

		/*switch(i) {*/
			/*case 1:*/
				/*guessMax = guess;*/
				/*if(guessMax - guessMin < 2)*/
					/*guessMin -= 100;*/
				/*break;*/
			/*case 2:*/
				/*guessMin = guess;*/
				/*if(guessMax - guessMin < 2)*/
					/*guessMax += 100;*/
				/*break;*/
			/*case 3:*/
				/*printf("Found it!\n");*/
				/*exit = 1;*/
				/*break;*/
			/*case 4:*/
				/*exit = 1;*/
				/*break;*/
			/*default:*/
				/*printf("Invalid Input!\n");*/
				/*break;*/
		/*}*/

		/*guess = getRandomNumber(guessMax, guessMin);*/
	/*}*/

}

void getUserInput(int *u) {
	printf("Press 3 for ");
}

int evalOutput(int u, int c) {
	return 0;
}

int getRandomNumber(int max, int min) {
	return  (int)((rand() / (float)RAND_MAX) * (max - min - 1)) + min + 1;
}

#ifdef __unix__
void initTermios(int echo) {
	tcgetattr(0, &old);
	new = old;
	new.c_lflag &= ~ICANON;
	new.c_lflag &= echo ? ECHO: ~ECHO;
	tcsetattr(0, TCSANOW, &new);
}

void resetTermios() {
	tcsetattr(0, TCSANOW, &old);
}

char getch_(int echo) {
	char ch;
	initTermios(echo);
	ch = getchar();
	resetTermios();
	return ch;
}

char getch() {
	return getch_(0);
}

char getche() {
	return getch_(1);
}
#endif

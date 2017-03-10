#include "io.h"

#ifdef __unix__
static struct termios old, new;

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

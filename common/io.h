#include <stdio.h>

#ifdef __unix__
#include <termios.h>
#elif defined(_WIN32) || defined(WIN32)
#include <conio.h>
#endif

#ifdef __unix__
void initTermios(int echo);
void resetTermios();
char getch_(int echo);
char getch();
char getche();
#endif

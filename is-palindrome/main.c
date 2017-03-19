#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void getInput(long *num);
void numToString(long num, char **numArr, long *len);
int isPalindrome(char *numArr, long len);


int main() {
	long num, len;
	char *numArr;

	getInput(&num);
	if(num <= 0) {
		printf("number should be positive!\n");
		return 1;
	}
	numToString(num, &numArr, &len);
	int pal = isPalindrome(numArr, len);

	printf("%d\n", pal);

	return 0;
}

void getInput(long *num) {
	printf("Input Number: ");
	scanf("%ld", num);
}


void numToString(long num, char **numArr, long *len) {
	*len = log10(num) + 1;
	*numArr = (char *)malloc(sizeof(char) * (*len));
	char *a = *numArr;
	long t;
	while(num > 0) {
		t = num % 10;
		*a = '0' + t;
		a++;
		num = num / 10;
	}
}

int isPalindrome(char *numArr, long len) {
	long ls;
	if(len <= 1)
       		return 1;
	if(len % 2 == 0)
		ls = (len / 2) - 1;
	else
		ls = (len / 2);
	for(long i = 0; i <= ls; i++) {
		if(numArr[i] != numArr[len-i-1])
			return 0;
	}
	return 1;
}

#include <stdio.h>

static int x; // static global variable

void print_num(void) { //static funciton
	static int y = 0;
	printf("%d\n", y);
	y = y + 1;
}

int main(void) {
	print_num();
	print_num();
	print_num();
	return 0;
	}

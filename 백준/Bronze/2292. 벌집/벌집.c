#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a;
	int b;
	int c;
	int counter;

	counter = 0;
	c = 1;

	scanf("%d", &a);

	b = (a - 1);

	if (a == 1) {
		printf("%d", a);
		return 0;
	}

	else if (a > 1 && a < 8) {
		printf("2");
		return 0;
	}

	while (b > 0) {
		counter += 1;
		b -= (6 * c);
		c += 1;


	}
	printf("%d", counter + 1);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int a;
	int i = 0;
	int b, c, d, e;

	scanf("%d", &a);

	if (a < 10) {
		e = a;
		a = (a * 10) + a;
		i += 1;
	}
	else {
		e = a;
		b = a / 10;
		c = a % 10;
		d = b + c;
		a = (c * 10) + (d % 10);
		i += 1;
	}

	while (a != e) {
		if (a < 10) {
			a = (a * 10) + a;
		}
		else {
			b = a / 10;
			c = a % 10;
			d = b + c;
			a = (c * 10) + (d % 10);
		}
		i += 1;
	}

	printf("%d", i);

	return 0;
}
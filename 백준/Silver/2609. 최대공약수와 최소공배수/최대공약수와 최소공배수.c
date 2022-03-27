#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int a, b, c, d, e, i;

	scanf("%d %d", &a, &b);

	i = 1;
	d = b;
	e = a;

	while (i <= a && i <= b) {
		if (a % i == 0 && b % i == 0) {
			c = i;
			i++;
		}
		else {
			i++;
		}
	}

	if (a > b) {
		d = b * (a / b);
	}
	else if (a < b) {
		e = a * (b / a);
	}

	while (d != e) {
		if (e > d) {
			d += b;
		}
		else if (e < d) {
			e += a;
		}
	}

	printf("%d\n", c);
	printf("%d", e);

	return 0;
}
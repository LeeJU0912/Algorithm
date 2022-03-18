#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b, c, d, e, f, g;

	scanf("%d %d", &a, &b);
	scanf("%d", &c);

	d = c / 60;
	e = c % 60;
	f = b + e;

	if (f >= 60) {
		f = f - 60;
		d++;
	}
	
	g = a + d;

	if (g >= 24) {
		g = g - 24;
	}
	printf("%d %d", g, f);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a;
	int b = 666;
	int c[1000];
	int d;
	int i = 1;
	int g ;
	int x;

	scanf("%d", &a);

	while (i < a) {
		b += 1;
		d = b;
		g = 0;
		while (d >= 1) {
			c[g] = d % 10;
			d = d / 10;
			g += 1;
		}
		g -= 1;
		for (x = 0; x < g - 1; x++) {
			if (c[g - x] == 6 && c[g - (x + 1)] == 6 && c[g - (x + 2)] == 6) {
				i += 1;
				break;
			}
			else {
				continue;
			}
		}
	}

	printf("%d", b);

	return 0;
}
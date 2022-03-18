#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b, c, d, e, f, g;
	int arr[8];
	scanf("%d %d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7]);

	b = 8;
	c = 1;

	for (a = 0; a < 8; a++) {
		if (arr[a] == a + 1) {
			if (a == 7) {
				printf("ascending");
				c = 0;
			}
		}
		else {
			break;
		}
	}

	for (a = 0; a < 8; a++) {
		if (arr[a] == b - a) {
			if (a == 7) {
				printf("descending");
				c = 0;
			}
		}
		else {
			break;
		}
	}

	if (c == 1) {
		printf("mixed");
	}

	return 0;
}
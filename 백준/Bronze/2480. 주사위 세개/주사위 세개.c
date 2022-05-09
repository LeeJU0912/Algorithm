#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int a, b, c, d, i;
    int arr[10] = { 0, };
    int arr2[10] = { 0, };
    int e, f;

    scanf("%d %d %d", &a, &b, &c);

    if (a == b && b == c) {
        d = 10000 + a * 1000;
    }
    else if (a == b) {
        d = 1000 + a * 100;
    }
    else if (a == c) {
        d = 1000 + a * 100;
    }
    else if (b == c) {
        d = 1000 + b * 100;
    }
    else {
        if (a > b && a > c) {
            d = a * 100;
        }
        else if (b > a && b > c) {
            d = b * 100;
        }
        else if (c > a && c > b) {
            d = c * 100;
        }
    }

    printf("%d", d);

    return 0;
}
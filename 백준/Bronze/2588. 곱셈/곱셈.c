#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int a, b, c, d, e;

    scanf("%d", &a);
    scanf("%d", &b);

    c = b % 10;
    d = b / 10 % 10;
    e = b / 100 % 10;

    printf("%d\n", a * c);
    printf("%d\n", a * d);
    printf("%d\n", a * e);
    printf("%d", a * b);

    return 0;
}
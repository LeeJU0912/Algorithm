#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int a;
    int b;

    scanf("%d %d", &a, &b);
    {
        if (a >= 0, b <= 10000) {
            printf("%d\n", a + b);
            printf("%d\n", a - b);
            printf("%d\n", a * b);
            printf("%d\n", a / b);
            printf("%d", a % b);
        }
    }
    return 0;
}
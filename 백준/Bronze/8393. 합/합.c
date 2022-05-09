#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int n, i;
    int result = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        result = result + i;
    }
    printf("%d", result);

    return 0;
}
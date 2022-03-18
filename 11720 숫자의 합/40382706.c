#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int a, b, c, d, i;
    int arr[100] = {0, };
    c = 0;

    scanf("%d", &a);



    for (i = 0; i < a; i++) {
        scanf("%1d", &arr[i]);
        c = c + arr[i];

    }

    printf("%d", c);

    return 0;
}
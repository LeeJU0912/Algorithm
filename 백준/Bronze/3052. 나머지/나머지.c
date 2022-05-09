#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int a, b, c, d, i;
    int arr[10] = { 0, };
    int arr2[10] = { 0, };
    int e, f;

    c = 1;

    for (i = 0; i < 10; i++) {
        
        scanf("%d", &arr2[i]);

        arr[i] = arr2[i] % 42;
        
    }

    for (i = 0; i < 9; i++) {
        for (e = 9; e > i; e--) {
            f = arr[i] - arr[e];

            if (f == 0) {
                arr[i] = -1;
                c = c - 1;
            }
        }
        c = c + 1;
    }

    printf("%d", c);

    return 0;
}
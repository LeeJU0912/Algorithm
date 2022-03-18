#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int a, b, c, d, i;
    int arr1[3] = { 0, 0, 0 };
    int arr2[3] = { 0, 0, 0 };
    
    int e, f;

    scanf("%d %d", &c, &d);

    for (i = 0; i < 3; i++) {

        arr1[i] = c % 10;
        arr2[i] = d % 10;

        c = c / 10;
        d = d / 10;
        

    }

    a = arr1[0] * 100 + arr1[1] * 10 + arr1[2];
    b = arr2[0] * 100 + arr2[1] * 10 + arr2[2];

    if (a > b) {
        printf("%d%d%d", arr1[0], arr1[1], arr1[2]);
    }
    else if (a < b) {
        printf("%d%d%d", arr2[0], arr2[1], arr2[2]);
    }

    return 0;
}
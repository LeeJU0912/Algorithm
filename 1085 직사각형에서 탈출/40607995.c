#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int a, b, c, d, e, f;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a > c - a) {
        e = c - a;
    }
    else {
        e = a;
    }
    
    if (b > d - b) {
        f = d - b;
    }
    else {
        f = b;
    }

    if (e > f) {
        printf("%d", f);
    }
    else if (f > e) {
        printf("%d", e);
    }
    else {
        printf("%d", e);
    }


    return 0;
}
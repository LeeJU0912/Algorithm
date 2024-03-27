#include <stdio.h>

char ans[31];

int main()
{
    long long a, b;
    scanf("%lld %lld",&a,&b);

    int idx = 0;
    long long div = 1;
    while(1) {
        if (div * b > a) break;
        div *= b;
    }
    while(a) {
        int mod = a / div;

        char now;
        if (mod >= 10) {
            now = 'A' + (mod - 10);
        }
        else {
            now = '0' + mod;
        }

        ans[idx++] = now;

        a -= mod * div;
        div /= b;
    }

    while(div) {
        ans[idx++] = '0';
        div /= b;
    }

    for (int i = 0; i < idx; i++) {
        printf("%c", ans[i]);
    }

    return 0;
}
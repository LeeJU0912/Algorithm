#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    char save[101];
    scanf("%s", save);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += save[i] - '0';
    }

    printf("%d", ans);
}

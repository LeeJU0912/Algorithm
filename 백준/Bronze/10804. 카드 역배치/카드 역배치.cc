#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int save[21];

int main() {
    FastIO

    for (int i = 1; i <= 20; i++) {
        save[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j <= (b - a) / 2; j++) {
            int tmp = save[a + j];
            save[a + j] = save[b - j];
            save[b - j] = tmp;
        }
    }

    for (int i = 1; i <= 20; i++) {
        cout << save[i] << ' ';
    }

    return 0;
}
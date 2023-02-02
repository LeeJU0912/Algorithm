#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int save[45][2];

int main() {
    FastIO

    int K;
    cin >> K;

    save[0][1] = 1;
    save[1][0] = 1;
    save[1][1] = 1;

    for (int i = 2; i < K; i++) {
        save[i][1] = save[i - 2][1] + save[i - 1][1];
        save[i][0] = save[i - 2][0] + save[i - 1][0];
    }

    cout << save[K - 1][0] << ' ' << save[K - 1][1];

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int DP[(1 << 5)][25];

int main() {
    FastIO

    DP[(1 << 1) | (1 << 2) | (1 << 3) | (1 << 4)][1] = 1;
    DP[(1 << 1) | (1 << 2) | (1 << 3) | (1 << 4)][2] = 5;
    DP[(1 << 1) | (1 << 2) | (1 << 3) | (1 << 4)][3] = 11;
    DP[(1 << 1) | (1 << 2) | (1 << 3) | (1 << 4)][4] = 36;

    for (int i = 5; i <= 24; i++) {
        DP[(1 << 1) | (1 << 2) | (1 << 3) | (1 << 4)][i] =
                DP[(1 << 1) | (1 << 2) | (1 << 3) | (1 << 4)][i - 1]
                + DP[(1 << 1) | (1 << 2) | (1 << 3) | (1 << 4)][i - 2] * 5
                + DP[(1 << 1) | (1 << 2) | (1 << 3) | (1 << 4)][i - 3]
                - DP[(1 << 1) | (1 << 2) | (1 << 3) | (1 << 4)][i - 4];
    }

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;

        cout << DP[30][N] << '\n';
    }

    return 0;
}
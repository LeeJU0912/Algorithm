#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
bool chk[301][301];
int DP[301][301];

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int C, R;
        cin >> C >> R;
        chk[C - R + 100][C + R + 100] = true;
    }

    for (int i = 0; i < 300; i++) {
        for (int j = 1; j <= 300 - i; j++) {
            for (int k = j; k <= j + i; k++) {
                DP[j][j + i] = max(DP[j][j + i], DP[j][k] + DP[k][j + i] + chk[j][j + i]);
            }

        }
    }

    cout << N - DP[1][300] / 2;

    return 0;
}
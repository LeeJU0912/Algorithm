#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int SCV[3];
int DP[61][61][61];

int splash[6][3] = {{9, 3, 1},
                    {9, 1, 3},
                    {3, 9, 1},
                    {3, 1, 9},
                    {1, 3, 9},
                    {1, 9, 3}};

void solve(int counter, int a, int b, int c) {
    a = min(a, SCV[0]);
    b = min(b, SCV[1]);
    c = min(c, SCV[2]);

    if (DP[a][b][c] <= counter) return;
    DP[a][b][c] = counter;

    if (a == SCV[0] && b == SCV[1] && c == SCV[2]) return;

    for (int i = 0; i < 6; i++) {
        solve(counter + 1, a + splash[i][0], b + splash[i][1], c + splash[i][2]);
    }
}

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> SCV[i];
    }

    for (int i = 0; i <= SCV[0]; i++) {
        for (int j = 0; j <= SCV[1]; j++) {
            for (int k = 0; k <= SCV[2]; k++) {
                DP[i][j][k] = INT_MAX;
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        solve(1, splash[i][0], splash[i][1], splash[i][2]);
    }

    cout << DP[SCV[0]][SCV[1]][SCV[2]];

    return 0;
}
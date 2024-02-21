#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int board[1001][1001];
int DP[1001][1001][3];

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];

            for (int k = 0; k < 3; k++) {
                DP[i][j][k] = -1e9;
            }
        }
    }

    for (int i = 1; i <= M; i++) {
        DP[1][i][0] = DP[1][i - 1][0] + board[1][i];
    }

    if (N >= 2) {
        for (int i = 1; i <= M; i++) {
            DP[2][i][1] = DP[1][i][0] + board[2][i];
        }
        for (int i = 2; i < N; i++) {
            for (int j = 2; j <= M; j++) {
                DP[i][j][0] = max(DP[i][j - 1][0], DP[i][j - 1][1]) + board[i][j];
            }
            for (int j = M - 1; j >= 1; j--) {
                DP[i][j][2] = max(DP[i][j + 1][2], DP[i][j + 1][1]) + board[i][j];
            }
            for (int j = 1; j <= M; j++) {
                DP[i + 1][j][1] = max(DP[i][j][0], max(DP[i][j][1], DP[i][j][2])) + board[i + 1][j];
            }
        }
        for (int i = 2; i <= M; i++) {
            DP[N][i][0] = max(DP[N][i - 1][1], DP[N][i - 1][0]) + board[N][i];
        }
    }

    cout << max(DP[N][M][0], DP[N][M][1]);

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
bool board[17][17];
int DP[17][17][3];

int main() {
    FastIO

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    DP[1][2][2] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 3; j <= N; j++) {
            if (board[i][j]) continue;
            DP[i][j][0] = DP[i - 1][j][0] + DP[i - 1][j][1];
            DP[i][j][2] = DP[i][j - 1][1] + DP[i][j - 1][2];

            if (board[i][j] || board[i - 1][j] || board[i][j - 1]) continue;
            DP[i][j][1] = DP[i - 1][j - 1][0] + DP[i - 1][j - 1][1] + DP[i - 1][j - 1][2];
        }
    }

    cout << DP[N][N][0] + DP[N][N][1] + DP[N][N][2];

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int board[501][501];
int DP[501][501];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M) return 1;
    if (DP[x][y]) return DP[x][y];

    DP[x][y] = -1;

    int nextX = x + dx[board[x][y]];
    int nextY = y + dy[board[x][y]];

    DP[x][y] = dfs(nextX, nextY);

    return DP[x][y];
}

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < M; j++) {
            if (s[j] == 'U') {
                board[i][j] = 0;
            }
            else if (s[j] == 'R') {
                board[i][j] = 1;
            }
            else if (s[j] == 'D') {
                board[i][j] = 2;
            }
            else if (s[j] == 'L') {
                board[i][j] = 3;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (DP[i][j]) continue;
            dfs(i, j);
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (DP[i][j] == 1) ans++;
        }
    }

    cout << ans;

    return 0;
}
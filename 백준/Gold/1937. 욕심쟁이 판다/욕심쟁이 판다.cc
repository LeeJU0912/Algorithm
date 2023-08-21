#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
int board[501][501];
int DP[501][501];

int ans;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int solve(int x, int y) {
    if (DP[x][y]) return DP[x][y];
    DP[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x <= 0 || next_x > n || next_y <= 0 || next_y > n) continue;
        if (board[next_x][next_y] <= board[x][y]) continue;
        DP[x][y] = max(DP[x][y], solve(next_x, next_y) + 1);
    }

    return DP[x][y];
}

int main() {
    FastIO

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = max(ans, solve(i, j));
        }
    }

    cout << ans;

    return 0;
}
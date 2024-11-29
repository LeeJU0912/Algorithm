#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int R, C, K;
bool board[5][5];
bool visited[5][5];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans;

void solve(int x, int y, int cnt) {
    if (x == 0 && y == C - 1) {
        if (cnt == K) {
            ans++;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x < 0 || next_x >= R || next_y < 0 || next_y >= C) continue;
        if (board[next_x][next_y]) continue;
        if (visited[next_x][next_y]) continue;
        visited[next_x][next_y] = true;
        solve(next_x, next_y, cnt + 1);
        visited[next_x][next_y] = false;
    }
}

int main() {
    FastIO

    cin >> R >> C >> K;
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < C; j++) {
            if (s[j] == 'T') {
                board[i][j] = true;
            }
        }
    }

    visited[R - 1][0] = true;
    solve(R - 1, 0, 1);

    cout << ans;

    return 0;
}
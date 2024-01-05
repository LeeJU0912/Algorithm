#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

int board[5][5];

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int ans1 = INT_MIN;
int ans2 = INT_MAX;

void solve(int x, int y, int order_standby, int hap) {
    if (x == N - 1 && y == N - 1) {
        ans1 = max(ans1, hap);
        ans2 = min(ans2, hap);
        return;
    }

    for (int i = 0; i < 2; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x >= N || next_y >= N) continue;

        if (board[next_x][next_y] == -1) {
            solve(next_x, next_y, -1, hap);
        }
        else if (board[next_x][next_y] == -2) {
            solve(next_x, next_y, -2, hap);
        }
        else if (board[next_x][next_y] == -3) {
            solve(next_x, next_y, -3, hap);
        }
        else {
            if (order_standby == -1) solve(next_x, next_y, 0, hap + board[next_x][next_y]);
            else if (order_standby == -2) solve(next_x, next_y, 0, hap - board[next_x][next_y]);
            else if (order_standby == -3) solve(next_x, next_y, 0, hap * board[next_x][next_y]);
        }
    }
}

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;

            if (c == '+') board[i][j] = -1;
            else if (c == '-') board[i][j] = -2;
            else if (c == '*') board[i][j] = -3;
            else board[i][j] = c - '0';
        }
    }

    solve(0, 0, 0, board[0][0]);

    cout << ans1 << ' ' << ans2;

    return 0;
}
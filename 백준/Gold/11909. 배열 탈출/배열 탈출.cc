#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
int board[2222][2222];
int DP[2222][2222];

int dx[2] = {0, 1};
int dy[2] = {1, 0};

void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});

    DP[0][0] = 0;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 2; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if (next_x >= n || next_y >= n) continue;
            if (board[now.first][now.second] <= board[next_x][next_y]) {
                if (DP[now.first][now.second] + (board[next_x][next_y] - board[now.first][now.second] + 1) >= DP[next_x][next_y]) continue;
                DP[next_x][next_y] = DP[now.first][now.second] + (board[next_x][next_y] - board[now.first][now.second] + 1);
                q.push({next_x, next_y});
            }
            else {
                if (DP[now.first][now.second] >= DP[next_x][next_y]) continue;
                DP[next_x][next_y] = DP[now.first][now.second];
                q.push({next_x, next_y});
            }
        }
    }
}

int main() {
    FastIO

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];

            DP[i][j] = 1e9;
        }
    }

    bfs();

    cout << DP[n - 1][n - 1];

    return 0;
}
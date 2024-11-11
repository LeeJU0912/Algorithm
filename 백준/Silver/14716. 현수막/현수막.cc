#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int M, N;
int board[251][251];
bool visited[251][251];
int ans;

int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = { -1, 0, 1, 1, -1, 0, 1, -1};

void solve(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if (next_x < 0 || next_x >= M || next_y < 0 || next_y >= N) continue;
            if (board[next_x][next_y] == 0) continue;
            if (visited[next_x][next_y]) continue;
            visited[next_x][next_y] = true;

            q.push({next_x, next_y});
        }
    }
}

int main() {
    FastIO

    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] || board[i][j] == 0) continue;
            solve(i, j);
            ans++;
        }
    }

    cout << ans;

    return 0;
}
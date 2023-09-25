#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int board[101][101];
bool visited[101][101];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans;

int solve(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    int counter = 0;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        counter++;

        for (int i = 0; i < 4; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) continue;
            if (board[next_x][next_y] == 0) continue;
            if (visited[next_x][next_y]) continue;
            visited[next_x][next_y] = true;
            q.push({next_x, next_y});
        }
    }

    return counter;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        board[a - 1][b - 1] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j]) continue;
            if (board[i][j]) ans = max(ans, solve(i, j));
        }
    }

    cout << ans;

    return 0;
}
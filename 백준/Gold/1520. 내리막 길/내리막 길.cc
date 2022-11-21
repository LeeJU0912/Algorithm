#include <bits/stdc++.h>

using namespace std;

int M, N;
int board[501][501];
int DP[501][501];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans;

//void bfs(int x, int y) {
//    queue<pair<pair<int, int>, int>> q;
//    q.push({{x, y}, 0});
//
//    while(!q.empty()) {
//        auto now = q.front();
//        q.pop();
//
//        for (int i = 0; i < 4; i++) {
//            int next_x = now.first.first + dx[i];
//            int next_y = now.first.second + dy[i];
//
//            if (next_x >= M || next_x < 0 || next_y >= N || next_y < 0) continue;
//            if (board[now.first.first][now.first.second] <= board[next_x][next_y]) continue;
//            if (next_x == M - 1 && next_y == N - 1) {
//                ans++;
//                continue;
//            }
//            q.push({{next_x, next_y}, now.second + 1});
//        }
//    }
//}

int dfs(int x, int y) {
    if (x == M - 1 && y == N - 1) return 1;

    if (DP[x][y] == -1) {
        DP[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x >= M || next_x < 0 || next_y >= N || next_y < 0) continue;
            if (board[x][y] <= board[next_x][next_y]) continue;
            DP[x][y] += dfs(next_x, next_y);
        }
    }

    return DP[x][y];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            DP[i][j] = -1;
        }
    }
    dfs(0, 0);

    cout << DP[0][0];

    return 0;
}
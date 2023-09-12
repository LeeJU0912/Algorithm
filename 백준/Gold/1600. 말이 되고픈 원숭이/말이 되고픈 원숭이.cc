#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int K, W, H;
int board[201][201];
int visited[201][201][31];
int horse_x[8] = {1, 2, 1, 2, -1, -2, -1, -2};
int horse_y[8] = {2, 1, -2, -1, -2, -1, 2, 1};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int ans = INT_MAX;

void solve() {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 0}, {0, 0}});
    visited[0][0][0] = 0;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        if (now.second.first == H - 1 && now.second.second == W - 1) {
            return;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = now.second.first + dx[i];
            int next_y = now.second.second + dy[i];

            if (next_x < 0 || next_x >= H || next_y < 0 || next_y >= W) continue;
            if (board[next_x][next_y]) continue;
            if (visited[next_x][next_y][now.first.second]) continue;
            visited[next_x][next_y][now.first.second] = now.first.first + 1;
            q.push({{now.first.first + 1, now.first.second}, {next_x, next_y}});
        }

        if (now.first.second == K) continue;

        for (int i = 0; i < 8; i++) {
            int next_horse_x = now.second.first + horse_x[i];
            int next_horse_y = now.second.second + horse_y[i];

            if (next_horse_x < 0 || next_horse_x >= H || next_horse_y < 0 || next_horse_y >= W) continue;
            if (board[next_horse_x][next_horse_y]) continue;
            if (visited[next_horse_x][next_horse_y][now.first.second + 1]) continue;
            visited[next_horse_x][next_horse_y][now.first.second + 1] = now.first.first + 1;
            q.push({{now.first.first + 1, now.first.second + 1}, {next_horse_x, next_horse_y}});
        }
    }
}

int main() {
    FastIO

    cin >> K >> W >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> board[i][j];
        }
    }

    if (W == 1 && H == 1) {
        cout << 0;
        return 0;
    }

    solve();

    for (int i = 0; i <= K; i++) {
        if (visited[H - 1][W - 1][i] == 0) continue;
        ans = min(ans, visited[H - 1][W - 1][i]);
    }

    if (ans == INT_MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }


    return 0;
}
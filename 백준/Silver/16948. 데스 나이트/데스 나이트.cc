#include <bits/stdc++.h>
using namespace std;

int N;
int r1, c1, r2, c2;
int DP[201][201];

int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};

void solve() {
    queue<pair<int, int>> q;
    q.push({r1, c1});
    DP[r1][c1] = 0;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        if (now.first == r2 && now.second == c2) return;

        for (int i = 0; i < 6; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;
            if (DP[next_x][next_y] != INT_MAX) continue;
            DP[next_x][next_y] = DP[now.first][now.second] + 1;
            q.push({next_x, next_y});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    cin >> r1 >> c1 >> r2 >> c2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            DP[i][j] = INT_MAX;
        }
    }

    solve();

    if (DP[r2][c2] == INT_MAX) {
        cout << -1;
    }
    else {
        cout << DP[r2][c2];
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

int board[501][501];
bool visited[501][501];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans = INT_MAX;

void solve() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {0, 0}});
    visited[0][0] = true;

    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (now.second.first == 500 && now.second.second == 500) {
            ans = now.first;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = now.second.first + dx[i];
            int next_y = now.second.second + dy[i];

            if (next_x < 0 || next_x > 500 || next_y < 0 || next_y > 500) continue;
            if (visited[next_x][next_y]) continue;
            visited[next_x][next_y] = true;

            if (board[next_x][next_y] == 2) continue;
            else if (board[next_x][next_y] == 1) pq.push({now.first + 1, {next_x, next_y}});
            else pq.push({now.first, {next_x, next_y}});
        }
    }
}

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        int X1, Y1, X2, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;

        for (int x = min(X1, X2); x <= max(X1, X2); x++) {
            for (int y = min(Y1, Y2); y <= max(Y1, Y2); y++) {
                board[x][y] = 1;
            }
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int X1, Y1, X2, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;

        for (int x = min(X1, X2); x <= max(X1, X2); x++) {
            board[x][Y1] = 2;
            board[x][Y2] = 2;
        }
        for (int y = min(Y1, Y2); y <= max(Y1, Y2); y++) {
            board[X1][y] = 2;
            board[X2][y] = 2;
        }
    }

    solve();

    if (ans == INT_MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }

    return 0;
}
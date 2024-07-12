#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m;
bool board[1001][1001];
int dist[1001][1001];
int startX, startY;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void solve() {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    dist[startX][startY] = 0;

    while(!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
            if (board[next_x][next_y]) continue;
            if (dist[next_x][next_y] != -1) continue;

            dist[next_x][next_y] = dist[now_x][now_y] + 1;
            q.push({next_x, next_y});
        }
    }
}

int main() {
    FastIO

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = -1;

            int temp;
            cin >> temp;

            if (temp == 0) {
                board[i][j] = true;
            }
            else if (temp == 2) {
                startX = i;
                startY = j;
            }
        }
    }

    solve();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (board[i][j] ? 0 : dist[i][j]) << ' ';
        }
        cout << '\n';
    }

    return 0;
}
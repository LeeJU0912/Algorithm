#include <bits/stdc++.h>
using namespace std;

int R, C;
int board[251][251];
bool visited[251][251];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans1;
int ans2;

void solve(int x, int y) {
    int lamb = 0;
    int wolf = 0;

    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        if (board[now.first][now.second] == 1) {
            wolf++;
        }
        else if (board[now.first][now.second] == 2) {
            lamb++;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if (next_x < 0 || next_x >= R || next_y < 0 || next_y >= C) continue;
            if (board[next_x][next_y] == 3) continue;
            if (visited[next_x][next_y]) continue;
            visited[next_x][next_y] = true;

            q.push({next_x, next_y});
        }
    }

    if (lamb > wolf) ans1 += lamb;
    else ans2 += wolf;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < C; j++) {
            if (s[j] == '#') {
                board[i][j] = 3;
            }
            else if (s[j] == 'v') {
                board[i][j] = 1;
            }
            else if (s[j] == 'o') {
                board[i][j] = 2;
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 3) continue;
            if (visited[i][j]) continue;
            solve(i, j);
        }
    }

    cout << ans1 << ' ' << ans2;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[101][101];
bool visited[101][101];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans1, ans2;

int count_w(int x, int y) {
    int counter = 0;

    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        counter++;

        for (int i = 0; i < 4; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if (next_x < 0 || next_x >= M || next_y < 0 || next_y >= N) continue;
            if (visited[next_x][next_y]) continue;
            if (board[next_x][next_y] == 1) continue;
            visited[next_x][next_y] = true;
            q.push({next_x, next_y});
        }
    }

    return counter * counter;
}

int count_b(int x, int y) {
    int counter = 0;

    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        counter++;

        for (int i = 0; i < 4; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if (next_x < 0 || next_x >= M || next_y < 0 || next_y >= N) continue;
            if (visited[next_x][next_y]) continue;
            if (board[next_x][next_y] == 0) continue;
            visited[next_x][next_y] = true;
            q.push({next_x, next_y});
        }
    }

    return counter * counter;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++) {
            if (s[j] == 'B') {
                board[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;
            if (board[i][j] == 0) {
                ans1 += count_w(i, j);
            }
            else if (board[i][j] == 1) {
                ans2 += count_b(i, j);
            }
        }
    }

    cout << ans1 << ' ' << ans2;

    return 0;
}
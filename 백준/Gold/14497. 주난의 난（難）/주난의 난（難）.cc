#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

int x_1, y_1, x_2, y_2;

int board[301][301];
bool visited[301][301];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans = -1;

int counter;

void solve() {
    queue<pair<int, int>> q;
    q.push({x_1, y_1});
    visited[x_1][y_1] = true;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();
        
        if (now.first == x_2 && now.second == y_2) {
            ans = counter;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if (next_x <= 0 || next_x > N || next_y <= 0 || next_y > M) continue;
            if (visited[next_x][next_y]) continue;
            visited[next_x][next_y] = true;

            if (board[next_x][next_y] == 1) {
                board[next_x][next_y] = 0;
            }
            else q.push({next_x, next_y});
        }
    }
}

int main() {
    FastIO

    cin >> N >> M;

    cin >> x_1 >> y_1 >> x_2 >> y_2;

    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < M; j++) {
            if (s[j] == '1') board[i][j + 1] = 1;
            else if (s[j] == '#') board[i][j + 1] = 2;
        }
    }

    while(ans == -1) {
        counter++;
        solve();
        memset(visited, false, sizeof(visited));
    }

    cout << ans;

    return 0;
}
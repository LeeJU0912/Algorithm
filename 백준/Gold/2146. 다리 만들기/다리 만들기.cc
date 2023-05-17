#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int board[100][100];
int island[100][100];
bool visited[100][100];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

set<pair<int, pair<int, int>>> start;

int island_num = 1;

int ans = INT_MAX;

void make_island(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        island[now.first][now.second] = island_num;

        for (int i = 0; i < 4; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;
            if (visited[next_x][next_y]) continue;
            if (board[next_x][next_y] == 0) {
                start.insert({island_num, now});
                continue;
            }
            visited[next_x][next_y] = true;

            q.push({next_x, next_y});
        }
    }
    island_num++;
}

void make_bridge(pair<int, pair<int, int>> go) {
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {go.second.first, go.second.second}});
    visited[go.second.first][go.second.second] = true;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        if (island[now.second.first][now.second.second] != go.first && island[now.second.first][now.second.second] != 0) {
            ans = min(ans, now.first);
            break;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = now.second.first + dx[i];
            int next_y = now.second.second + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;
            if (visited[next_x][next_y]) continue;
            if (island[next_x][next_y] == island_num) continue;
            visited[next_x][next_y] = true;

            q.push({now.first + 1, {next_x, next_y}});
        }
    }
}

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) continue;
            if (visited[i][j]) continue;

            make_island(i, j);
        }
    }

    for (auto i : start) {
        memset(visited, false, sizeof(visited));
        make_bridge(i);
    }

    if (ans == INT_MAX) {
        cout << 0;
    }
    else {
        cout << ans - 1;
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int R, C;
int maze[1001][1001];
bool visited[1001][1001];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

pair<int, int> start;
queue<pair<int, int>> fire;

int bfs() {
    queue<pair<int, pair<int, int>>> q;
    q.emplace(0, start);
    visited[start.first][start.second] = true;

    while(!q.empty()) {
        int fire_size = fire.size();

        for (int i = 0; i < fire_size; i++) {
            auto now_fire = fire.front();
            fire.pop();

            for (int j = 0; j < 4; j++) {
                int next_fire_x = now_fire.first + dx[j];
                int next_fire_y = now_fire.second + dy[j];

                if (next_fire_x < 0 || next_fire_x >= R || next_fire_y < 0 || next_fire_y >= C) continue;
                if (maze[next_fire_x][next_fire_y]) continue;
                maze[next_fire_x][next_fire_y] = 2;
                fire.emplace(next_fire_x, next_fire_y);
            }
        }

        int q_size = q.size();

        for (int i = 0; i < q_size; i++) {
            auto now = q.front();
            q.pop();

            if (now.second.first == 0 || now.second.first == R - 1 || now.second.second == 0 || now.second.second == C - 1) {
                return now.first + 1;
            }

            for (int j = 0; j < 4; j++) {
                int next_x = now.second.first + dx[j];
                int next_y = now.second.second + dy[j];

                if (next_x < 0 || next_x >= R || next_y < 0 || next_y >= C) continue;
                if (maze[next_x][next_y]) continue;
                if (visited[next_x][next_y]) continue;
                visited[next_x][next_y] = true;
                q.push({now.first + 1, {next_x, next_y}});
            }
        }
    }
    return 0;
}

int main() {
    FastIO

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            if (s[j] == '#') {
                maze[i][j] = 1;
            }
            else if (s[j] == 'J') {
                start = {i, j};
            }
            else if (s[j] == 'F') {
                fire.emplace(i, j);
                maze[i][j] = 2;
            }
        }
    }

    int result = bfs();
    if (result) {
        cout << result;
    }
    else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}
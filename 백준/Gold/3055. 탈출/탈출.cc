#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int R, C;
int graph[51][51];
bool visited[51][51];

int dx[4] = {0, 0, -1 ,1};
int dy[4] = {1, -1, 0, 0};

pair<int, int> start;

queue<pair<int, int>> water;

int ans;

void bfs() {
    queue<pair<pair<int, int>, int>> q;
    q.emplace(start, 0);
    visited[start.first][start.second] = true;

    while(!q.empty()) {
        int water_search = water.size();
        for (int i = 0; i < water_search; i++) {
            auto now_water = water.front();
            water.pop();
            for (int j = 0; j < 4; j++) {
                int next_x_water = now_water.first + dx[j];
                int next_y_water = now_water.second + dy[j];
                if (next_x_water < 0 || next_x_water >= R || next_y_water < 0 || next_y_water >= C) continue;
                if (graph[next_x_water][next_y_water] != 0) continue;
                graph[next_x_water][next_y_water] = 1;
                water.emplace(next_x_water, next_y_water);
            }
        }

        int go_way = q.size();
        for (int i = 0; i < go_way; i++) {
            auto now = q.front();
            q.pop();

            for (int j = 0; j < 4; j++) {
                int next_x = now.first.first + dx[j];
                int next_y = now.first.second + dy[j];

                if (next_x < 0 || next_x >= R || next_y < 0 || next_y >= C) continue;
                if (visited[next_x][next_y]) continue;
                if (graph[next_x][next_y] == 1 || graph[next_x][next_y] == 4) continue;
                visited[next_x][next_y] = true;
                if (graph[next_x][next_y] == 3) {
                    ans = now.second + 1;
                    return;
                }
                q.push({{next_x, next_y}, now.second + 1});
            }
        }
    }
}

int main() {
    FastIO

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            if (s[j] == '*') {
                graph[i][j] = 1;
                water.emplace(i, j);
            }
            else if (s[j] == 'D') {
                graph[i][j] = 3;
            }
            else if (s[j] == 'S') {
                graph[i][j] = 2;
                start = {i, j};
            }
            else if (s[j] == 'X') {
                graph[i][j] = 4;
            }
        }
    }

    bfs();

    if (ans) {
        cout << ans;
    }
    else {
        cout << "KAKTUS";
    }

    return 0;
}
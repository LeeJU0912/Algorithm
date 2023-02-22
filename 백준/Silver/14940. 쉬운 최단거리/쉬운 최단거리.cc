#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m;
int start_x, start_y;
int graph[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[1001][1001];

void bfs() {
    queue<pair<int, int>> q;
    q.emplace(start_x, start_y);
    visited[start_x][start_y] = true;
    graph[start_x][start_y] = 0;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
            if (visited[next_x][next_y]) continue;
            if (graph[next_x][next_y] == 0) continue;
            visited[next_x][next_y] = true;
            graph[next_x][next_y] = graph[now.first][now.second] + 1;
            q.emplace(next_x, next_y);
        }
    }
}

int main() {
    FastIO

    cin >> n >> m;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 2) {
                start_x = i;
                start_y = j;
            }
        }
    }

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && graph[i][j] != 0) {
                graph[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
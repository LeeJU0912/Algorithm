#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;


int N, M;

int graph[101][71];
int graph2[101][71];
bool visited[101][71];

int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

int ans;

bool bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visited[x][y] = true;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) continue;
            if (visited[next_x][next_y]) continue;
            visited[next_x][next_y] = true;

            if (graph[next_x][next_y] > graph[now.first][now.second]) return false;
            else if (graph[next_x][next_y] == graph[now.first][now.second]) {
                q.emplace(next_x, next_y);
            }

        }
    }

    graph2[x][y] = graph[x][y];

    return true;
}

int main() {
    FastIO


    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ans += bfs(i, j);
            memset(visited, false, sizeof(visited));
        }
    }

    int ans2 = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph2[i][j]) {
                if (visited[i][j]) continue;
                ans2 += bfs(i, j);
            }
        }
    }

    cout << ans2;

    return 0;
}
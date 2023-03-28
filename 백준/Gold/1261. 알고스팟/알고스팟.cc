#include <bits/stdc++.h>
using namespace std;

int N, M;
int graph[101][101];
int break_min[101][101];
bool visited[101][101];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs() {
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    break_min[0][0] = 0;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) continue;

            if (graph[next_x][next_y] == 1) {
                if (break_min[next_x][next_y] > break_min[now.first][now.second] + 1) {
                    break_min[next_x][next_y] = break_min[now.first][now.second] + 1;
                    q.emplace(next_x, next_y);
                }
            }
            else {
                if (break_min[next_x][next_y] > break_min[now.first][now.second]) {
                    break_min[next_x][next_y] = break_min[now.first][now.second];
                    q.emplace(next_x, next_y);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            break_min[i][j] = INT_MAX;

            if (s[j] == '1') {
                graph[i][j] = 1;
            }
        }
    }

    bfs();

    cout << break_min[N - 1][M - 1];

    return 0;
}
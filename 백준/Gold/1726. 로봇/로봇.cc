#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};

bool board[101][101];
bool visited[101][101][5];

pair<int, int> one, two;
int one_dir, two_dir;

void solve() {
    priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<>> pq;
    pq.push({{0, one_dir}, one});
    visited[one.first][one.second][one_dir] = true;

    while(!pq.empty()) {
        int now_x = pq.top().second.first;
        int now_y = pq.top().second.second;
        int counter = pq.top().first.first;
        int now_dir = pq.top().first.second;
        pq.pop();

        if (now_x == two.first && now_y == two.second && now_dir == two_dir) {
            cout << counter;
            return;
        }

        for (int i = 1; i <= 4; i++) {
            if (now_dir == 1 && i == 2) continue;
            if (now_dir == 2 && i == 1) continue;
            if (now_dir == 3 && i == 4) continue;
            if (now_dir == 4 && i == 3) continue;
            
            for (int j = 0; j <= 3; j++) {
                int next_x = now_x + dx[i] * j;
                int next_y = now_y + dy[i] * j;

                if (now_dir != i) {
                    if (visited[now_x][now_y][i]) break;
                    visited[now_x][now_y][i] = true;
                    pq.push({{counter + 1, i}, {now_x, now_y}});
                    break;
                }
                else {
                    if (j == 0) continue;
                    if (next_x <= 0 || next_x > N || next_y <= 0 || next_y > M) break;
                    if (board[next_x][next_y]) break;
                    if (visited[next_x][next_y][i]) continue;
                    visited[next_x][next_y][i] = true;

                    pq.push({{counter + 1, i}, {next_x, next_y}});
                }
            }
        }
    }
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

    cin >> one.first >> one.second >> one_dir;
    cin >> two.first >> two.second >> two_dir;

    solve();

    return 0;
}
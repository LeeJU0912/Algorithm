#include <bits/stdc++.h>
using namespace std;

int M, N, K;
int board[101][101];
bool visited[101][101];
int ans;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<int> ans1;

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    board[x][y] = 1;

    int temp = 0;

    while(!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        temp++;

        for (int i = 0; i < 4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x >= M || next_x < 0 || next_y >= N || next_y < 0) continue;
            if (board[next_x][next_y] != 0) continue;
            if (visited[next_x][next_y]) continue;

            visited[next_x][next_y] = true;
            q.push({next_x, next_y});
            board[next_x][next_y] = board[now_x][now_y] + 1;
        }
    }
    return temp;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        int start_x, end_x, start_y, end_y;
        cin >> start_x >> start_y >> end_x >> end_y;

        for (int j = start_y; j < end_y; j++) {
            for (int k = start_x; k < end_x; k++) {
                board[j][k] = 1;
            }
        }
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] || board[i][j] == 1) continue;
            ans++;
            ans1.push_back(bfs(i, j));
        }
    }

    sort(ans1.begin(), ans1.end());

    cout << ans << '\n';

    for (auto i : ans1) {
        cout << i << ' ';
    }

    return 0;
}
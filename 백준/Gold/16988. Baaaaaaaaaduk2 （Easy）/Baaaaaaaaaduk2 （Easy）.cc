#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int board[20][20];
bool visited[20][20];

vector<pair<int, int>> blank;
vector<pair<int, int>> opponent;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans;

int getAll(int x, int y) {
    int ret = 1;
    bool cannot = false;

    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = now.first + dx[i];
            int nextY = now.second + dy[i];

            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
            if (board[nextX][nextY] == 0) {
                cannot = true;
                continue;
            }
            else if (board[nextX][nextY] == 1) continue;
            if (visited[nextX][nextY]) continue;
            visited[nextX][nextY] = true;

            q.push({nextX, nextY});
            ret++;
        }
    }

    if (cannot) return 0;
    else return ret;
}

void chk() {
    memset(visited, false, sizeof(visited));

    int tmp = 0;

    for (auto now : opponent) {
        if (visited[now.first][now.second]) continue;

        tmp += getAll(now.first, now.second);
    }

    ans = max(ans, tmp);
}

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                blank.push_back({i, j});
            }
            else if (board[i][j] == 2) {
                opponent.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < blank.size() - 1; i++) {
        for (int j = i + 1; j < blank.size(); j++) {
            auto b1 = blank[i];
            auto b2 = blank[j];

            board[b1.first][b1.second] = 1;
            board[b2.first][b2.second] = 1;

            chk();

            board[b1.first][b1.second] = 0;
            board[b2.first][b2.second] = 0;
        }
    }

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int board[51][51];
bool visited[51][51];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool ans;

void solve(int x, int y) {
    int same = board[x][y];

    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{x, y}, {-1, -1}});
    visited[x][y] = true;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = now.first.first + dx[i];
            int next_y = now.first.second + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) continue;
            if (board[next_x][next_y] != same) continue;
            if (visited[next_x][next_y]) {
                if (next_x == now.second.first && next_y == now.second.second) continue;

                ans = true;
                return;
            }
            visited[next_x][next_y] = true;

            q.push({{next_x, next_y}, now.first});
        }
    }
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < M; j++) {
            board[i][j] = s[j] - 'A';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ans) break;
            if (visited[i][j]) continue;
            solve(i, j);
        }
        if (ans) break;
    }

    cout << (ans ? "Yes" : "No");

    return 0;
}
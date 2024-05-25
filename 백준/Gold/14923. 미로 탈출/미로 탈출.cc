#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int Hx, Hy, Ex, Ey;
bool board[1001][1001];
bool visited[1001][1001][2];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans = -1;

void solve() {
    queue<pair<pair<int, int>, pair<int, bool>>> q;
    q.push({{Hx - 1, Hy - 1}, {0, false}});
    visited[Hx - 1][Hy - 1][0] = true;

    while(!q.empty()) {
        int now_x = q.front().first.first;
        int now_y = q.front().first.second;
        int now_val = q.front().second.first;
        int power = q.front().second.second;
        q.pop();

        if (now_x == Ex - 1 && now_y == Ey - 1) {
            ans = now_val;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) continue;
            if (visited[next_x][next_y][power]) continue;
            if (board[next_x][next_y]) {
                if (power) continue;
                visited[next_x][next_y][1] = true;
                q.push({{next_x, next_y}, {now_val + 1, true}});
            }
            else {
                visited[next_x][next_y][power] = true;
                q.push({{next_x, next_y}, {now_val + 1, power}});
            }
        }
    }
}

int main() {
    FastIO

    cin >> N >> M;
    cin >> Hx >> Hy;
    cin >> Ex >> Ey;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    solve();

    cout << ans;

    return 0;
}
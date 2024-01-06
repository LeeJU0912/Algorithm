#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, K;

bool visited[3000][3000];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans = -1;

bool cant_go(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M) return true;
    else return false;
}

void fill_line(int x, int y) {
    if (cant_go(x, y)) return;
    visited[x][y] = true;
}

void busy(int x, int y, int dist) {
    for (int i = 0; i <= dist; i++) {
        int next_x = x + i;
        int next_y = y + (dist - i);

        fill_line(next_x, next_y);

        next_x = x - i;
        fill_line(next_x, next_y);

        next_y = y - (dist - i);
        fill_line(next_x, next_y);

        next_x = x + i;
        fill_line(next_x, next_y);
    }
}

void solve() {
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});
    visited[0][0] = true;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        if (now.second.first == N - 1 && now.second.second == M - 1) {
            ans = now.first;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = now.second.first + dx[i];
            int next_y = now.second.second + dy[i];

            if (cant_go(next_x, next_y)) continue;
            if (visited[next_x][next_y]) continue;
            visited[next_x][next_y] = true;

            q.push({now.first + 1, {next_x, next_y}});
        }
    }
}

int main() {
    FastIO

    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        int r, c, d;
        cin >> r >> c >> d;
        busy(r - 1, c - 1, d);
    }

    solve();

    if (ans != -1) {
        cout << "YES" << '\n' << ans;
    }
    else cout << "NO";

    return 0;
}
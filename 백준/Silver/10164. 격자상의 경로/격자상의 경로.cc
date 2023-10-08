#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, K;
int DP[15][15];
bool visited[15][15];

int dx[2] = {0, 1};
int dy[2] = {1, 0};

int circle_x, circle_y;

int ans;

void to_circle(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 2; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if (next_x > circle_x || next_y > circle_y) continue;
            DP[next_x][next_y] += DP[now.first][now.second];
            if (visited[next_x][next_y]) continue;
            visited[next_x][next_y] = true;
            q.push({next_x, next_y});
        }
    }
}

void to_last(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 2; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if (next_x >= N || next_y >= M) continue;
            DP[next_x][next_y] += DP[now.first][now.second];
            if (visited[next_x][next_y]) continue;
            visited[next_x][next_y] = true;
            q.push({next_x, next_y});
        }
    }
}

int main() {
    FastIO

    cin >> N >> M >> K;

    DP[0][0] = 1;

    if (K != 0) {
        circle_x = K / M;
        circle_y = K % M;

        if (circle_y == 0) {
            circle_y = M;
            circle_x--;
        }
        circle_y--;

        to_circle(0, 0);
        ans += DP[circle_x][circle_y];
        
        DP[circle_x][circle_y] = 1;
        to_last(circle_x, circle_y);
        ans *= DP[N - 1][M - 1];
    }
    else {
        to_last(0, 0);
        ans = DP[N - 1][M - 1];
    }

    cout << ans;

    return 0;
}
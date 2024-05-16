#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, K;
bool board[1001][1001];

int dx[5] = {0, 0, -1, 1, 0};
int dy[5] = {1, -1, 0, 0, 0};

int DP[1001][1001][11][2];

int ans = INT_MAX;

struct INFO {
    int x, y;
    bool day;
    int break_counter;
    int move_counter;
};

void solve() {
    queue<INFO> q;
    q.push({0, 0, true, 0, 1});
    DP[0][0][0][1] = 1;

    while(!q.empty()) {
        INFO now = q.front();
        q.pop();

        if (now.x == N - 1 && now.y == M - 1) {
            ans = min(ans, now.move_counter);
            continue;
        }

        if (now.move_counter >= ans) continue;

        for (int i = 0; i < 5; i++) {
            int next_x = now.x + dx[i];
            int next_y = now.y + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) continue;

            // 벽 뚫기
            if (now.day && board[next_x][next_y] && now.break_counter < K) {
                if (DP[next_x][next_y][now.break_counter + 1][0] <= now.move_counter + 1) continue;

                DP[next_x][next_y][now.break_counter + 1][0] = now.move_counter + 1;
                q.push({next_x, next_y, false, now.break_counter + 1, now.move_counter + 1});
                DP[next_x][next_y][now.break_counter + 1][1] = now.move_counter + 2;
                q.push({next_x, next_y, true, now.break_counter + 1, now.move_counter + 2});
            }

            // 벽 없는 다음 칸
            if (board[next_x][next_y] == 0) {
                if (DP[next_x][next_y][now.break_counter][!now.day] <= now.move_counter + 1) continue;

                DP[next_x][next_y][now.break_counter][!now.day] = now.move_counter + 1;
                q.push({next_x, next_y, !now.day, now.break_counter, now.move_counter + 1});
            }
        }
    }
}

int main() {
    FastIO

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < M; j++) {
            board[i][j] = s[j] - '0';

            for (int k = 0; k <= K; k++) {
                DP[i][j][k][0] = INT_MAX;
                DP[i][j][k][1] = INT_MAX;
            }
        }
    }

    solve();

    cout << (ans == INT_MAX ? -1 : ans);

    return 0;
}
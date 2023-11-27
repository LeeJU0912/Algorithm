#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int board[21][21];

vector<pair<int, int>> coin;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans = INT_MAX;

bool chk_out(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M) return true;
    else return false;
}

bool wall_chk(int x, int y) {
    if (board[x][y]) return true;
    else return false;
}

void solve() {
    queue<pair<int, pair<int, int>>> q1, q2;

    q1.push({0, coin[0]});
    q2.push({0, coin[1]});

    while(!q1.empty() && !q2.empty()) {
        auto now1 = q1.front();
        auto now2 = q2.front();
        q1.pop();
        q2.pop();

        if (now1.first > 10) continue;

        for (int i = 0; i < 4; i++) {
            int next1_x = now1.second.first + dx[i];
            int next1_y = now1.second.second + dy[i];
            int next2_x = now2.second.first + dx[i];
            int next2_y = now2.second.second + dy[i];

            if (chk_out(next1_x, next1_y) && chk_out(next2_x, next2_y)) continue;
            else if (chk_out(next1_x, next1_y) ^ chk_out(next2_x, next2_y)) {
                ans = min(ans, now1.first + 1);
                continue;
            }

            if (wall_chk(next1_x, next1_y)) {
                next1_x = now1.second.first;
                next1_y = now1.second.second;
            }
            if (wall_chk(next2_x, next2_y)) {
                next2_x = now2.second.first;
                next2_y = now2.second.second;
            }

            if (next1_x == next2_x && next1_y == next2_y) continue;

            q1.push({now1.first + 1, {next1_x, next1_y}});
            q2.push({now2.first + 1, {next2_x, next2_y}});
        }
    }
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;

            if (c == 'o') {
                coin.push_back({i, j});
            }
            else if (c == '#') {
                board[i][j] = 1;
            }
        }
    }

    solve();

    if (ans > 10) {
        cout << -1;
    }
    else {
        cout << ans;
    }

    return 0;
}
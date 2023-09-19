#include <bits/stdc++.h>
using namespace std;

int R, C;
int board[10001][501];
int dx[3] = {1, 0, -1};

int cnt = 2;
int ans;



void solve(int x) {
    stack<pair<int, int>> stk;
    stk.push({x, 0});
    board[x][0] = cnt;

    while(!stk.empty()) {
        auto now = stk.top();
        stk.pop();

        board[now.first][now.second] = cnt;

        if (now.second == C - 1) {
            ans++;
            return;
        }

        for (int i = 0; i < 3; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + 1;
            if (next_x < 0 || next_x >= R || next_y < 0 || next_y >= C) continue;
            if (board[next_x][next_y]) continue;

            stk.push({next_x, next_y});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < C; j++) {
            if (s[j] == 'x') {
                board[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < R; i++) {
        solve(i);
        cnt++;
    }

    cout << ans;

    return 0;
}
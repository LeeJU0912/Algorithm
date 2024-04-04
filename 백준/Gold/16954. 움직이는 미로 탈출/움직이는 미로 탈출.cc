#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

bool board[8][8];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void move_maze() {
    for (int i = 6; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            board[i + 1][j] = board[i][j];
        }
    }

    for (int i = 0; i < 8; i++) {
        board[0][i] = false;
    }
}

bool solve() {
    queue<pair<int, int>> q;
    q.push({7, 0});

    while(!q.empty()) {
        int qsize = q.size();
        for (int x = 0; x < qsize; x++) {
            int now_x = q.front().first;
            int now_y = q.front().second;
            q.pop();

            if (now_x == 0 && now_y == 7) return true;
            if (board[now_x][now_y]) continue;

            for (int i = 0; i < 8; i++) {
                int next_x = now_x + dx[i];
                int next_y = now_y + dy[i];

                if (next_x < 0 || next_x >= 8 || next_y < 0 || next_y >= 8) continue;
                if (board[next_x][next_y]) continue;

                q.push({next_x, next_y});
            }
            q.push({now_x, now_y});
        }
        move_maze();
    }
    return false;
}

int main() {
    FastIO

    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            if (s[j] == '#') board[i][j] = true;
        }
    }

    cout << solve();

    return 0;
}
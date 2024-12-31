#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int M, N;
int board[1001][1001];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void go(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    board[x][y] = 2;

    while(!q.empty()) {
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];

            if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
            if (board[nextX][nextY]) continue;
            board[nextX][nextY] = 2;
            q.push({nextX, nextY});
        }
    }
}

bool chk() {
    for (int i = 0; i < N; i++) {
        if (board[M - 1][i] == 2) return true;
    }

    return false;
}

int main() {
    FastIO

    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++) {
           board[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        if (!board[0][i]) {
            go(0, i);
        }
    }

    cout << (chk() ? "YES" : "NO");

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, x, y, K;
int board[20][20];

int now_x, now_y;

int dice[6];

bool is_out(int a, int b) {
    if (a < 0 || a >= N || b < 0 || b >= M) return true;
    else return false;
}

void roll(int order) {
    int save = dice[0];

    if (order == 1) {
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[3];
        dice[3] = save;
    }
    else if (order == 2) {
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[1];
        dice[1] = save;
    }
    else if (order == 3) {
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[2];
        dice[2] = save;
    }
    else {
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[4];
        dice[4] = save;
    }
}

int main() {
    FastIO

    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    now_x = x;
    now_y = y;

    for (int i = 0; i < K; i++) {
        int order;
        cin >> order;

        int next_x, next_y;

        if (order == 1) {
            next_x = now_x;
            next_y = now_y + 1;
            if (is_out(next_x, next_y)) continue;
        }
        else if (order == 2) {
            next_x = now_x;
            next_y = now_y - 1;
            if (is_out(next_x, next_y)) continue;
        }
        else if (order == 3) {
            next_x = now_x - 1;
            next_y = now_y;
            if (is_out(next_x, next_y)) continue;
        }
        else {
            next_x = now_x + 1;
            next_y = now_y;
            if (is_out(next_x, next_y)) continue;
        }

        roll(order);

        if (board[next_x][next_y] == 0) {
            board[next_x][next_y] = dice[0];
        }
        else {
            dice[0] = board[next_x][next_y];
            board[next_x][next_y] = 0;
        }

        now_x = next_x;
        now_y = next_y;

        cout << dice[5] << '\n';
    }

    return 0;
}
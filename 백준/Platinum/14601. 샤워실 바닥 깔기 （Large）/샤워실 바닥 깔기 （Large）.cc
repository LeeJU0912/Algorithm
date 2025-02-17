#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int K;
int a, b;

int board[128][128];

int cnt;

bool notVisited(int x, int y, int len) {
    for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
            if (board[i][j]) return false;
        }
    }
    return true;
}

void solve(int x, int y, int len) {
    if (len == 1) return;
    cnt++;

    int next = len >> 1;

    if (notVisited(x, y, next)) {
        board[x + next - 1][y + next - 1] = cnt;
    }
    if (notVisited(x + next, y, next)) {
        board[x + next][y + next - 1] = cnt;
    }
    if (notVisited(x, y + next, next)) {
        board[x + next - 1][y + next] = cnt;
    }
    if (notVisited(x + next, y + next, next)) {
        board[x + next][y + next] = cnt;
    }

    solve(x, y, next);
    solve(x + next, y, next);
    solve(x, y + next, next);
    solve(x + next, y + next, next);
}

int main() {
    FastIO

    cin >> K >> a >> b;
    board[a - 1][b - 1] = -1;

    int len = (1 << K);

    solve(0, 0, len);

    for (int i = len - 1; i >= 0; i--) {
        for (int j = 0; j < len; j++) {
            cout << board[j][i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
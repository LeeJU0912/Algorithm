#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

int board[4][4];
bool visited[4][4];

int ans;

void solve(int x, int y, int hap) {
    if (x == N) {
        ans = max(ans, hap);
        return;
    }
    if (visited[x][y]) {
        if (y == M - 1) {
            solve(x + 1, 0, hap);
        }
        else {
            solve(x, y + 1, hap);
        }
        return;
    }

    int now = board[x][y];
    int next = now;

    if (y == M - 1) {
        solve(x + 1, 0, hap + next);
    }
    else {
        solve(x, y + 1, hap + next);
    }

    for (int i = y + 1; i < M; i++) {
        if (visited[x][i]) break;
        next *= 10;
        next += board[x][i];

        if (i == M - 1) {
            solve(x + 1, 0, hap + next);
        }
        else {
            solve(x, i + 1, hap + next);
        }
    }


    for (int X = 1; X < N - x; X++) {
        if (visited[x + X][y]) break;
        next = now;
        for (int i = x + 1; i <= x + X; i++) {
            next *= 10;
            next += board[i][y];
            visited[i][y] = true;
        }
        if (y == M - 1) {
            solve(x + 1, 0, hap + next);
        }
        else {
            solve(x, y + 1, hap + next);
        }
        for (int i = x + 1; i <= x + X; i++) {
            visited[i][y] = false;
        }
    }
}

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < M; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    solve(0, 0, 0);

    cout << ans;

    return 0;
}
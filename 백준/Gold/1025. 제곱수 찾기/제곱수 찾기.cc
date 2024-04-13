#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int board[9][9];

int ans = -1;

bool validate(int n) {

    for (int i = 0; i <= 31623; i++) {
        if (n == i * i) return true;
    }

    return false;
}

void solve(int x, int y, int multi_x, int multi_y) {
    int n = board[x][y];

    if (multi_x == 0 && multi_y == 0) {
        if (validate(n)) {
            ans = max(ans, n);
        }
        return;
    }

    for (int i = 1; x + multi_x * i >= 0 && x + multi_x * i < N && y + multi_y * i >= 0 && y + multi_y * i < M; i++) {
        n *= 10;
        n += board[x + multi_x * i][y + multi_y * i];

        if (validate(n)) {
            ans = max(ans, n);
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

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int x = -8; x < 9; x++) {
                for (int y = -8; y < 9; y++) {
                    solve(i, j, x, y);
                }
            }
        }
    }

    cout << ans;

    return 0;
}
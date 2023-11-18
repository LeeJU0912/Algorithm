#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int board[11][11];
int limit[6];

int one_counter;

int ans = INT_MAX;

bool chk_K(int x, int y, int K) {
    for (int i = x; i <= x + K; i++) {
        for (int j = y; j <= y + K; j++) {
            if (board[i][j] == 0) return false;
        }
    }
    return true;
}

void visit_K(int x, int y, int K) {
    for (int i = x; i <= x + K; i++) {
        for (int j = y; j <= y + K; j++) {
            board[i][j] = 0;
        }
    }
}
void unvisit_K(int x, int y, int K) {
    for (int i = x; i <= x + K; i++) {
        for (int j = y; j <= y + K; j++) {
            board[i][j] = 1;
        }
    }
}

void stick(int chk, int cnt) {
    if (cnt >= ans) return;
    if (chk == one_counter) {
        ans = min(ans, cnt);
        return;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board[i][j] == 0) continue;
            for (int k = 4; k >= 0; k--) {
                if (limit[k] == 5) continue;
                if (i + k >= 10 || j + k >= 10) continue;
                if (!chk_K(i, j, k)) continue;

                limit[k]++;
                visit_K(i, j, k);

                stick(chk + (k + 1) * (k + 1), cnt + 1);

                limit[k]--;
                unvisit_K(i, j, k);
            }
            return;
        }
    }
}

int main() {
    FastIO

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
            if (board[i][j]) one_counter++;
        }
    }

    stick(0, 0);

    if (ans == INT_MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }

    return 0;
}
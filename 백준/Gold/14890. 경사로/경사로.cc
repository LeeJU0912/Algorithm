#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, L;
int board[100][100];
bool visited[100][100];

bool chk(int idx, int order) {
    // 가로
    if (order == 1) {
        int now = board[idx][0];
        for (int i = 1; i < N; i++) {
            if (abs(board[idx][i] - now) > 1) return false;
            else if (abs(board[idx][i] - now) == 1) {
                if (board[idx][i] < now) {
                    for (int j = 0; j < L; j++) {
                        if (board[idx][i + j] != board[idx][i]) return false;
                        visited[idx][i + j] = true;
                    }
                    i += L - 1;
                }
                else {
                    for (int j = 1; j <= L; j++) {
                        if (i - j < 0) return false;
                        if (board[idx][i - 1] != board[idx][i - j]) return false;
                        if (visited[idx][i - j]) return false;
                        visited[idx][i - j] = true;
                    }
                }
            }
            now = board[idx][i];
        }
    }
    // 세로
    else {
        int now = board[0][idx];
        for (int i = 1; i < N; i++) {
            if (abs(board[i][idx] - now) > 1) return false;
            else if (abs(board[i][idx] - now) == 1) {
                if (board[i][idx] < now) {
                    for (int j = 0; j < L; j++) {
                        if (board[i][idx] != board[i + j][idx]) return false;
                        visited[i + j][idx] = true;
                    }
                    i += L - 1;
                }
                else {
                    for (int j = 1; j <= L; j++) {
                        if (i - j < 0) return false;
                        if (board[i - 1][idx] != board[i - j][idx]) return false;
                        if (visited[i - j][idx]) return false;
                        visited[i - j][idx] = true;
                    }
                }
            }
            now = board[i][idx];
        }
    }

    return true;
}

void clear(int idx, int order) {
    if (order == 1) {
        for (int i = 0; i < N; i++) {
            visited[idx][i] = false;
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            visited[i][idx] = false;
        }
    }
}

int main() {
    FastIO

    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += chk(i, 1);
        clear(i, 1);
        ans += chk(i, 2);
        clear(i, 2);
    }

    cout << ans;

    return 0;
}
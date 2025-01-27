#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, K;
int board[101][101];
int DP[101][101][81];

string X;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans;

void solve(int x, int y, int idx) {
    if (idx == X.size() - 1) {
        DP[x][y][idx] = 1;
        return;
    }

    if (DP[x][y][idx] == -1) {
        DP[x][y][idx] = 0;
    }

    for (int i = 0; i < 4; i++) {
        int nextX = x;
        int nextY = y;
        for (int j = 1; j <= K; j++) {
            nextX += dx[i];
            nextY += dy[i];
            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) break;
            if (board[nextX][nextY] != X[idx + 1] - 'A') continue;
            if (DP[nextX][nextY][idx + 1] >= 0) {
                DP[x][y][idx] += DP[nextX][nextY][idx + 1];
                continue;
            }

            solve(nextX, nextY, idx + 1);
            DP[x][y][idx] += DP[nextX][nextY][idx + 1];
        }
    }
}

int main() {
    FastIO

    memset(DP, -1, sizeof(DP));

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < M; j++) {
            board[i][j] = s[j] - 'A';
        }
    }

    cin >> X;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == X[0] - 'A') {
                solve(i, j, 0);
                ans += DP[i][j][0];
            }
        }
    }

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int board[100][100];
long long DP[100][100];

int dx[2] = {0, 1};
int dy[2] = {1, 0};

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    DP[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!DP[i][j]) continue;
            if (board[i][j] == 0) continue;

            for (int k = 0; k < 2; k++) {
                int next_x = i + dx[k] * board[i][j];
                int next_y = j + dy[k] * board[i][j];

                if (next_x >= N || next_y >= N) continue;

                DP[next_x][next_y] += DP[i][j];
            }
        }
    }

    cout << DP[N - 1][N - 1];

    return 0;
}
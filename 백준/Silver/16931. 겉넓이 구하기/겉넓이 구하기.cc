#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int board[102][102];

int ans;

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = 0; k < 4; k++) {
                int next_x = i + dx[k];
                int next_y = j + dy[k];

                ans += max(0, board[i][j] - board[next_x][next_y]);
            }
        }
    }

    cout << ans + (N * M) * 2;

    return 0;
}
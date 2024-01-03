#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

bool board[32][32];
long long DP[32][32][3];

queue<pair<int, int>> one, two, three;

bool can_one(int x, int y) {
    if (y + 1 == N) return false;
    if (board[x][y + 1]) return false;
    else return true;
}

bool can_two(int x, int y) {
    if (x + 1 == N) return false;
    if (board[x + 1][y]) return false;
    else return true;
}

bool can_three(int x, int y) {
    if (x + 1 == N || y + 1 == N) return false;
    if (board[x][y + 1] || board[x + 1][y] || board[x + 1][y + 1]) return false;
    else return true;
}

void solve() {
    DP[0][1][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (can_one(i, j)) {
                DP[i][j + 1][0] += DP[i][j][0] + DP[i][j][2];
            }
            if (can_two(i, j)) {
                DP[i + 1][j][1] += DP[i][j][1] + DP[i][j][2];
            }
            if (can_three(i, j)) {
                DP[i + 1][j + 1][2] += DP[i][j][0] + DP[i][j][1] + DP[i][j][2];
            }
        }
    }
}

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    solve();

    cout << DP[N - 1][N - 1][0] + DP[N - 1][N - 1][1] + DP[N - 1][N - 1][2];

    return 0;
}
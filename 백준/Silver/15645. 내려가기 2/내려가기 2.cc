#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int board[100001][3];
int DP[100001][3];

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> board[i][0] >> board[i][1] >> board[i][2];
    }

    DP[0][0] = board[0][0];
    DP[0][1] = board[0][1];
    DP[0][2] = board[0][2];

    for (int i = 1; i < N; i++) {
        DP[i][0] = max(DP[i - 1][0], DP[i - 1][1]) + board[i][0];
        DP[i][1] = max(max(DP[i - 1][0], DP[i - 1][1]), DP[i - 1][2]) + board[i][1];
        DP[i][2] = max(DP[i - 1][1], DP[i - 1][2]) + board[i][2];
    }
    int maxi = *max_element(DP[N - 1], DP[N - 1] + 3);

    memset(DP, 0, sizeof(DP));

    DP[0][0] = board[0][0];
    DP[0][1] = board[0][1];
    DP[0][2] = board[0][2];

    for (int i = 1; i < N; i++) {
        DP[i][0] = min(DP[i - 1][0], DP[i - 1][1]) + board[i][0];
        DP[i][1] = min(min(DP[i - 1][0], DP[i - 1][1]), DP[i - 1][2]) + board[i][1];
        DP[i][2] = min(DP[i - 1][1], DP[i - 1][2]) + board[i][2];
    }
    int mini = *min_element(DP[N - 1], DP[N - 1] + 3);

    cout << maxi << ' ' << mini;

    return 0;
}
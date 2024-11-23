#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int board[50][50];

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

    int mini = 2;
    int maxi = min(N, M);
    int ans = 1;
    for (int size = mini; size <= maxi; size++) {
        bool fine = false;

        for (int i = 0; i <= N - size; i++) {
            for (int j = 0; j <= M - size; j++) {
                int a = board[i][j];
                int b = board[i + size - 1][j];
                int c = board[i][j + size - 1];
                int d = board[i + size - 1][j + size - 1];

                if (a == b && b == c && c == d && d == a) {
                    fine = true;
                    break;
                }
            }
            if (fine) break;
        }

        if (fine) ans = size;
    }

    cout << ans * ans;

    return 0;
}
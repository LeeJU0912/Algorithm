#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int board[101][101];

int main() {
    FastIO

    for (int i = 0; i < 4; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for (int j = a; j < c; j++) {
            for (int k = b; k < d; k++) {
                board[j][k]++;
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (board[i][j]) {
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}
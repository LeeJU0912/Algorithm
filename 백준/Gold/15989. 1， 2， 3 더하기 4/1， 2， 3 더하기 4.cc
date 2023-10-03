#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
int DP[10001][4];

int main() {
    FastIO

    DP[1][1] = 1;
    DP[2][1] = 1;
    DP[2][2] = 1;
    DP[3][1] = 1;
    DP[3][2] = 1;
    DP[3][3] = 1;
    DP[4][1] = 1;
    DP[4][2] = 2;
    DP[4][3] = 1;

    for (int i = 5; i <= 10000; i++) {
        DP[i][1] = DP[i - 1][1];
        DP[i][2] = DP[i - 2][1] + DP[i - 2][2];
        DP[i][3] = DP[i - 3][1] + DP[i - 3][2] + DP[i - 3][3];
    }
    int T;
    cin >> T;

    while(T--) {
        cin >> n;
        cout << DP[n][1] + DP[n][2] + DP[n][3] << '\n';
    }

    return 0;
}
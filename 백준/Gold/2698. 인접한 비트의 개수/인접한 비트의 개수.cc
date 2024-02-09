#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int T;
int DP[101][101][2];

int main() {
    FastIO

    DP[1][0][0] = 1;
    DP[1][0][1] = 1;

    for (int i = 2; i <= 100; i++) {
        for (int j = 0; j < i; j++) {
            DP[i][j][0] = DP[i - 1][j][0] + DP[i - 1][j][1];
            DP[i][j][1] = DP[i - 1][j][0] + DP[i - 1][j - 1][1];
        }
    }

    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;

        cout << DP[n][k][0] + DP[n][k][1] << '\n';
    }

    return 0;
}
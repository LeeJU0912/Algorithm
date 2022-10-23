#include <bits/stdc++.h>
using namespace std;

int dp[1001][10];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0 ; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
        }
    }

    int ans = 0;

    for (int i = 0; i < 10; i++) {
        ans += dp[N][i];
    }

    cout << ans % 10007;

    return 0;
}
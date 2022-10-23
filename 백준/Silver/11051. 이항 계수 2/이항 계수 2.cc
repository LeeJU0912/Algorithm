#include <bits/stdc++.h>
using namespace std;

int N, K;

int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;

    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) dp[i][j] = 1;
            else if (j == i) dp[i][j] = 1;
            else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
            }
        }
    }

    cout << dp[N][K];

    return 0;
}
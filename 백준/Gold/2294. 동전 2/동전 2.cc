#include <bits/stdc++.h>
using namespace std;

int n, k;
int coin[100];
int dp[10001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> coin[i];
        if (coin[i] > k) continue;
        dp[coin[i]] = 1;
    }

    sort(coin, coin + n);

    for (int i = 0; i < k; i++) {
        if (dp[i] == 0) continue;
        for (int j = 0; j < n; j++) {
            if (i + coin[j] > k) break;
            if (dp[i + coin[j]] == 0) {
                dp[i + coin[j]] = dp[i] + 1;
            }
            else {
                dp[i + coin[j]] = min(dp[i] + 1, dp[i + coin[j]]);
            }
        }
    }

    if (!dp[k]) {
        cout << -1;
    }
    else {
        cout << dp[k];
    }

    return 0;
}
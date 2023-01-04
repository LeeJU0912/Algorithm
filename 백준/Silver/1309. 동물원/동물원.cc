#include <bits/stdc++.h>
using namespace std;

int dp[100001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    dp[1] = 3;
    dp[2] = 7;
    dp[3] = 17;

    for (int i = 4; i <= N; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1] * 2) % 9901;
    }

    cout << dp[N];

    return 0;
}
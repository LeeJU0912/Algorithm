#include <bits/stdc++.h>
using namespace std;

int N;
int temp[1001];
int dp[1001];
int ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> temp[i];
    }

    if (N == 1) {
        cout << temp[0];
        return 0;
    }

    sort(temp, temp + N);

    dp[0] = temp[0];
    dp[1] = max(temp[0] + temp[1], temp[0] * temp[1]);

    for (int i = 2; i < N; i++) {
        dp[i] = max(dp[i - 1] + temp[i], dp[i - 2] + (temp[i - 1] * temp[i]));
    }

    cout << dp[N - 1];


    return 0;
}
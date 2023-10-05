#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int S;
int DP[1001][1001];

int ans = INT_MAX;

void solve(int now, int counter, int copied) {
    if (now == S) {
        ans = min(ans, DP[now][copied]);
        return;
    }

    if (DP[now][now] > counter + 1) {
        DP[now][now] = counter + 1;
        solve(now, counter + 1, now);
    }
    if (now + copied > S) {
        ans = min(ans, counter + 1 + now + copied - S);
        return;
    }
    else {
        if (DP[now + copied][copied] > counter + 1) {
            DP[now + copied][copied] = counter + 1;
            solve(now + copied, counter + 1, copied);
        }
    }
    if (now > 0) {
        if (DP[now - 1][copied] > counter + 1) {
            DP[now - 1][copied] = counter + 1;
            solve(now - 1, counter + 1, copied);
        }
    }
}

int main() {
    FastIO

    cin >> S;

    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= S; j++) {
            DP[i][j] = INT_MAX;
        }
    }

    solve(1, 0, 0);

    cout << ans;

    return 0;
}
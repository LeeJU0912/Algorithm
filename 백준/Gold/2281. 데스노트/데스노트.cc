#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m;
int save[1001];
int DP[1001][1001];

int solve(int idx, int len) {
    if (idx > n) {
        return 0;
    }

    if (DP[idx][len] != -1) {
        return DP[idx][len];
    }

    DP[idx][len] = pow(m - len + 1, 2) + solve(idx + 1, save[idx] + 1);

    if (len + save[idx] <= m) {
        DP[idx][len] = min(DP[idx][len], solve(idx + 1, len + save[idx] + 1));
    }

    return DP[idx][len];
}

int main() {
    FastIO

    memset(DP, -1, sizeof(DP));

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> save[i];
    }

    cout << solve(1, 0);

    return 0;
}
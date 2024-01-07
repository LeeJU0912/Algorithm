#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int ans;

long long DP[101];

void solve() {
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 3;
    DP[4] = 4;
    DP[5] = 5;
    DP[6] = 6;

    for (int i = 7; i <= N; i++) {
        long long maxi = LLONG_MIN;

        for (int j = 1; j <= i - 3; j++) {
            maxi = max(maxi, DP[i - (j + 2)] * (j + 1));
        }

        DP[i] = max(DP[i - 1] + 1, maxi);
    }
}

int main() {
    FastIO

    cin >> N;

    if (N <= 6) {
        cout << N;
        return 0;
    }

    solve();

    cout << DP[N];

    return 0;
}
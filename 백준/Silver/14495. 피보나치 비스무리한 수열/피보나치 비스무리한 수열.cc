#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long DP[117];

int main() {
    FastIO

    int n;
    cin >> n;

    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 1;

    for (int i = 4; i <= n; i++) {
        DP[i] = DP[i - 1] + DP[i - 3];
    }

    cout << DP[n];

    return 0;
}
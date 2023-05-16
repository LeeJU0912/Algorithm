#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long DP[1000001];

long long calc(int now) {
    if (DP[now] != 0) return DP[now];

    DP[now] = calc(now - 3) + calc(now - 2) + calc(now - 1);
    DP[now] %= 1000000009;
    return DP[now];
}

int main() {
    FastIO

    int T;
    cin >> T;

    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;

    while(T--) {
        int n;
        cin >> n;

        cout << calc(n) << '\n';
    }

    return 0;
}
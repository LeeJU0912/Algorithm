#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int C, K, P;

int main() {
    FastIO

    cin >> C >> K >> P;

    long long ans = 0;
    for (int i = 1; i <= C; i++) {
        ans += K * i + P * i * i;
    }

    cout << ans;

    return 0;
}
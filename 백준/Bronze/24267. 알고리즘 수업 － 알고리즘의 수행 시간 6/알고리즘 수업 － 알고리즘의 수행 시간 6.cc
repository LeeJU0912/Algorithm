#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long n;

long long ans;

int main() {
    FastIO

    cin >> n;

    for (int i = 1; i <= n; i++) {
        ans += ((n - 1 - i) * (n - i)) / 2;
    }

    cout << ans << '\n' << 3;

    return 0;
}
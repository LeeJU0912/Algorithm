#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;


int main() {
    FastIO

    long long n;
    cin >> n;

    long long ans = 0;
    for (int i = 1; i <= n - 2; i++) {
        ans += (n - i - 1) * i;
    }

    cout << ans << '\n' << 3;

    return 0;
}
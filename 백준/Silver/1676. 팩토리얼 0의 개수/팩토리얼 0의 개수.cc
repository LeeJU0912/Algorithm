#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;

int main() {
    FastIO

    cin >> n;

    int ans = 0;

    for (int i = 5; i <= n; i *= 5) {
        ans += n / i;
    }

    cout << ans;

    return 0;
}
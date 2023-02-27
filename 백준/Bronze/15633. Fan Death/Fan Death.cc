#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) ans += i;
    }

    cout << ans * 5 - 24;

    return 0;
}
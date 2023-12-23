#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;


int main() {
    FastIO

    long long n;
    cin >> n;

    long long ans = 0;
    for (int i = 1; i < n; i++) {
        ans += i;
    }

    cout << ans << '\n' << 2;

    return 0;
}
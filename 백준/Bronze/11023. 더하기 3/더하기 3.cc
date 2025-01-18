#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int x;
    int ans = 0;
    while(cin >> x) {
        ans += x;
    }

    cout << ans;

    return 0;
}
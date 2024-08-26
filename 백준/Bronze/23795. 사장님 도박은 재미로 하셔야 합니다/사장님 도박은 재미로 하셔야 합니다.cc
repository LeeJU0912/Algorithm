#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int n;
    int ans = 0;

    while(true) {
        cin >> n;
        if (n == -1) break;
        ans += n;
    }

    cout << ans;

    return 0;
}
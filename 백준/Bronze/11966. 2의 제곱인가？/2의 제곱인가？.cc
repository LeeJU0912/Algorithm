#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    long long x;
    cin >> x;

    bool chk = false;
    bool ans = false;
    while(x > 0) {
        if (x & 1) {
            if (chk) {
                ans = false;
                break;
            }
            chk = true;
            ans = true;
        }
        x >>= 1;
    }

    cout << ans;

    return 0;
}
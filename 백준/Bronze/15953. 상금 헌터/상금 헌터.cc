#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        int a, b;
        cin >> a >> b;

        int ans = 0;
        if (a == 0) {

        }
        else if (a == 1) {
            ans += 5000000;
        }
        else if (a <= 3) {
            ans += 3000000;
        }
        else if (a <= 6) {
            ans += 2000000;
        }
        else if (a <= 10) {
            ans += 500000;
        }
        else if (a <= 15) {
            ans += 300000;
        }
        else if (a <= 21) {
            ans += 100000;
        }

        if (b == 0) {

        }
        else if (b == 1) {
            ans += 5120000;
        }
        else if (b <= 3) {
            ans += 2560000;
        }
        else if (b <= 7) {
            ans += 1280000;
        }
        else if (b <= 15) {
            ans += 640000;
        }
        else if (b <= 31) {
            ans += 320000;
        }

        cout << ans << '\n';
    }

    return 0;
}
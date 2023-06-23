#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int w, h;
    cin >> w >> h;

    int p, q;
    cin >> p >> q;

    int t;
    cin >> t;

    int ans1;
    int ans2;

    if (t + p <= w) {
        ans1 = t + p;
    }
    else if (!(((t - (w - p)) / w) % 2)) {
        ans1 = w - ((t - (w - p)) % w);
    }
    else {
        ans1 = (t - (w - p)) % w;
    }

    if (t + q <= h) {
        ans2 = t + q;
    }
    else if (((t - (h - q)) / h) % 2) {
        ans2 = (t - (h - q)) % h;
    }
    else {
        ans2 = h - ((t - (h - q)) % h);
    }

    cout << ans1 << ' ' << ans2;

    return 0;
}
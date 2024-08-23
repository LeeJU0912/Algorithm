#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    for (int i = 0; i < 3; i++) {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;

        d -= a;
        e -= b;
        f -= c;

        if (f < 0) {
            f += 60;
            e--;
        }
        if (e < 0) {
            e += 60;
            d--;
        }

        cout << d << ' ' << e << ' ' << f << '\n';
    }

    return 0;
}
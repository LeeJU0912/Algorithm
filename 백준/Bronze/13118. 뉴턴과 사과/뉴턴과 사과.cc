#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x, y, r;
    cin >> x >> y >> r;

    if (x == a) {
        cout << 1;
    }
    else if (x == b) {
        cout << 2;
    }
    else if (x == c) {
        cout << 3;
    }
    else if (x == d) {
        cout << 4;
    }
    else {
        cout << 0;
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int a, b;
    cin >> a >> b;

    int x = (a + b) / 2;
    int y = a - x;

    if (x - y != b) {
        cout << -1;
    }
    else {
        if (y < 0) {
            cout << -1;
        }
        else {
            cout << (a + b) / 2 << ' ' << a - (a + b) / 2;
        }
    }

    return 0;
}
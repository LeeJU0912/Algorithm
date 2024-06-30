#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int n;
    cin >> n;

    int x = 100;
    int y = 100;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (a < b) {
            x -= b;
        }
        else if (a > b) {
            y -= a;
        }
    }

    cout << x << '\n' << y;

    return 0;
}
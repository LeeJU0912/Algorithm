#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int a, b, c, d, e, f;
int x, y;

int main() {
    FastIO

    cin >> a >> b >> c >> d >> e >> f;

    for (int i = -999; i <= 999; i++) {
        for (int j = -999; j <= 999; j++) {
            if (a * i + b * j == c && d * i + e * j == f) {
                cout << i << ' ' << j;
                return 0;
            }
        }
    }


    return 0;
}
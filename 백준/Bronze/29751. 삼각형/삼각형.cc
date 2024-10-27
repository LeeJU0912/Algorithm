#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    double W, H;
    cin >> W >> H;

    cout << fixed;
    cout.precision(1);

    cout << (W * H) / 2;

    return 0;
}
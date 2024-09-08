#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    double d1, d2;
    cin >> d1 >> d2;

    cout << fixed;
    cout.precision(6);

    cout << d2 * 3.141592 * 2 + d1 * 2;

    return 0;
}
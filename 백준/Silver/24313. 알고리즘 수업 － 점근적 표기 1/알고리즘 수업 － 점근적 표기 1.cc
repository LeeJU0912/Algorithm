#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int a1, a0;

int c, n0;

int main() {
    FastIO

    cin >> a1 >> a0 >> c >> n0;

    if ((a1 <= c) && (a1 * n0 + a0 <= c * n0)) cout << 1;
    else cout << 0;

    return 0;
}
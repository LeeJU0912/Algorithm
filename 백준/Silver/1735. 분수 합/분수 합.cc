#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int a, b, c, d;

    cin >> a >> b >> c >> d;

    int e = b * d;
    int f = a * d;
    int g = b * c;
    int div = gcd((f + g), e);

    cout << (f + g) / div << ' ' << e / div;

    return 0;
}
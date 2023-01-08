#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string X, Y;

    cin >> X >> Y;

    int a = 0;
    int b = 0;
    for (int i = X.length() - 1; i >= 0; i--) {
        a *= 10;
        a += X[i] - '0';
    }

    for (int i = Y.length() - 1; i >= 0; i--) {
        b *= 10;
        b += Y[i] - '0';
    }

    int c = a + b;

    int d = 0;

    while(c != 0) {
        d *= 10;
        d += c % 10;
        c /= 10;
    }

    cout << d;

    return 0;
}
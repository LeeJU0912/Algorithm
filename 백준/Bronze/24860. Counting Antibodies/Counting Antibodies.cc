#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;



int main() {
    FastIO

    long long x[2];
    long long y;

    for (int i = 0; i < 2; i++) {
        int a, b;
        cin >> a >> b;
        x[i] = a * b;
    }

    int a, b, c;
    cin >> a >> b >> c;
    y = a * b * c;

    cout << (x[0] + x[1]) * y;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    if (A < 0) {
        cout << (C * -A) + D + (B * E);
    }
    else {
        cout << ((B - A) * E);
    }

    return 0;
}
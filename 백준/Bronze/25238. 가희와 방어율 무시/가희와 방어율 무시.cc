#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int a, b;
    cin >> a >> b;

    if (a * (100 - b) >= 10000) {
        cout << 0;
    }
    else {
        cout << 1;
    }

    return 0;
}
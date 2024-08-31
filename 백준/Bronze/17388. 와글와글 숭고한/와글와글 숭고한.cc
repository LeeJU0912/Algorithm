#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int a, b, c;

    cin >> a >> b >> c;

    if (a + b + c >= 100) {
        cout << "OK";
    }
    else {
        if (a < b && a < c) {
            cout << "Soongsil";
        }
        else if (b < a && b < c) {
            cout << "Korea";
        }
        else if (c < a && c < b) {
            cout << "Hanyang";
        }
    }

    return 0;
}
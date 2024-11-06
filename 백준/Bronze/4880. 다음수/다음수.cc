#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;


int main() {
    FastIO

    while(true) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0) break;

        if (b - a == c - b) {
            cout << "AP " << c + (c - b) << '\n';
        }
        else if (c / b == b / a) {
            cout << "GP " << c * (c / b) << '\n';
        }
    }

    return 0;
}
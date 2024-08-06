#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    while(true) {
        string a;
        int b, c;
        cin >> a >> b >> c;
        if (a == "#") break;

        if (b > 17 || c >= 80) {
            cout << a << ' ' << "Senior" << '\n';
        }
        else {
            cout << a << ' ' << "Junior" << '\n';
        }
    }

    return 0;
}
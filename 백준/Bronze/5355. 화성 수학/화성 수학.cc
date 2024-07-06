#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;

    cout << fixed;
    cout.precision(2);

    double now = DBL_MAX;
    string s;
    while(cin >> s) {
        if (s != "@" && s != "%" && s != "#") {
            if (now != DBL_MAX) cout << now << '\n';
            now = stod(s);
        }
        else if (s == "@") {
            now *= 3;
        }
        else if (s == "%") {
            now += 5;
        }
        else if (s == "#") {
            now -= 7;
        }
    }

    cout << now;

    return 0;
}
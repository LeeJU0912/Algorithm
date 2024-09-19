#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    string s;
    cin >> s;

    if (s.size() == 3) {
        if (s[1] == '0') {
            cout << s[2] - '0' + 10;
        }
        else {
            cout << s[0] - '0' + 10;
        }
    }
    else if (s.size() == 4) {
        cout << 20;
    }
    else {
        cout << s[0] - '0' + s[1] - '0';
    }

    return 0;
}
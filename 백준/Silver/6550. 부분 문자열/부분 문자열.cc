#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    string s, t;
    while(cin >> s >> t) {
        int idx = 0;
        for (int i = 0; i < t.length(); i++) {
            if (s[idx] == t[i]) {
                idx++;
            }
            if (idx == s.length()) break;
        }
        if (idx == s.length()) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }
    }

    return 0;
}
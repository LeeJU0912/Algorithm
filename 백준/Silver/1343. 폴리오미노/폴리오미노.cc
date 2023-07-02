#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    string s;
    cin >> s;

    for (int i = 0; i < s.length() - 1; i++) {
        if (i < s.length() - 3 && s[i] == 'X' && s[i + 1] == 'X' && s[i + 2] == 'X' && s[i + 3] == 'X') {
            s[i] = 'A';
            s[i + 1] = 'A';
            s[i + 2] = 'A';
            s[i + 3] = 'A';
            i += 3;
        }
        else if (s[i] == 'X' && s[i + 1] == 'X') {
            s[i] = 'B';
            s[i + 1] = 'B';
            i += 2;
        }
    }

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'X') {
            cout << -1;
            return 0;
        }
    }

    cout << s;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string s;

int main() {
    FastIO

    cin >> s;

    bool same_chk = false;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            same_chk = true;
            break;
        }
    }
    if (!same_chk) {
        cout << -1;
        return 0;
    }

    bool palindrome_chk = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            palindrome_chk = true;
            break;
        }
    }
    if (!palindrome_chk) {
        cout << s.size() - 1;
        return 0;
    }

    cout << s.size();

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string s;

int main() {
    FastIO

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        bool canPalindrome = true;
        for (int j = i; j <= s.size() - (s.size() - i) / 2; j++) {
            if (s[j] != s[s.size() - 1 - j + i]) {
                canPalindrome = false;
                break;
            }
        }

        if (canPalindrome) {
            cout << s.size() + i;
            return 0;
        }
    }

    cout << (s.size() - 1) * 2 + 1;

    return 0;
}
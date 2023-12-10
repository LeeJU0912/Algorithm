#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int T;

bool isPalindrome(const string& s) {
    for (int j = 0; j < s.size() / 2; j++) {
        if (s[j] != s[s.size() - 1 - j]) return false;
    }
    return true;
}

bool pseudoPalindrome(const string& s) {
    bool chance = false;
    bool left = false;
    bool right = false;

    for (int j = 0; j < s.size() / 2; j++) {
        if (chance) {
            if (s[j + 1] != s[s.size() - 1 - j]) {
                left = true;
            }
            if (s[j] != s[s.size() - 1 - j - 1]) {
                right = true;
            }
        }
        else if (s[j] != s[s.size() - 1 - j]) {
            chance = true;
            j--;
        }
    }

    if (left + right < 2) {
        return true;
    }
    else return false;
}

int main() {
    FastIO

    cin >> T;

    for (int i = 0; i < T; i++) {
        string s;
        cin >> s;

        if (isPalindrome(s)) {
            cout << 0 << '\n';
        }
        else if (pseudoPalindrome(s)) {
            cout << 1 << '\n';
        }
        else {
            cout << 2 << '\n';
        }
    }

    return 0;
}
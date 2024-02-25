#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string s;

bool solve() {
    if (count(s.begin(), s.end(), '*')) {
        int counter = 0;
        for (int i = 0; s[i] != '*'; i++) {
            if (s[i] == ')') counter--;
            else counter++;

            if (counter < 0) return false;
        }
        counter = 0;
        for (int i = s.length() - 1; s[i] != '*'; i--) {
            if (s[i] == '(') counter--;
            else counter++;

            if (counter < 0) return false;
        }
    }
    else {
        if (s.length() % 2) return false;

        int open = count(s.begin(), s.end(), '(');
        int close = count(s.begin(), s.end(), ')');

        if (open > s.length() / 2 || close > s.length() / 2) return false;

        int counter = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '?') {
                if (open < s.length() / 2) {
                    s[i] = '(';
                    open++;
                }
                else {
                    s[i] = ')';
                }
            }
            if (s[i] == '(') counter++;
            else if (s[i] == ')') counter--;

            if (counter < 0) return false;
        }
    }

    return true;
}

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        cin >> s;
        cout << (solve() ? "YES" : "NO") << '\n';
    }

    return 0;
}
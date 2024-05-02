#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        string ans;

        int counter = 0;
        for (int j = 0; j < s.size(); j++) {
            if (j <= s.size() - 3 && (s[j] == '\\' && s[j + 1] == '\\' && s[j + 2] == '\'')) {
                ans += 'w';
                j += 2;
            }
            else if (j <= s.size() - 2 && (s[j] == '\\' && s[j + 1] == '\'')) {
                ans += 'v';
                j++;
            }
            else if (s[j] == '@') {
                ans += 'a';
            }
            else if (s[j] == '[') {
                ans += 'c';
            }
            else if (s[j] == '!') {
                ans += 'i';
            }
            else if (s[j] == ';') {
                ans += 'j';
            }
            else if (s[j] == '^') {
                ans += 'n';
            }
            else if (s[j] == '0') {
                ans += 'o';
            }
            else if (s[j] == '7') {
                ans += 't';
            }
            else {
                ans += s[j];
                counter++;
            }
        }

        if (counter * 2 <= ans.size()) {
            cout << "I don't understand" << '\n';
        }
        else {
            cout << ans << '\n';
        }
    }

    return 0;
}
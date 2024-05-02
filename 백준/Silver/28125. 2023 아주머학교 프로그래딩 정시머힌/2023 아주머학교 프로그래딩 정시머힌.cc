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
                counter++;
                j += 2;
            }
            else if (j <= s.size() - 2 && (s[j] == '\\' && s[j + 1] == '\'')) {
                ans += 'v';
                counter++;
                j++;
            }
            else if (s[j] == '@') {
                ans += 'a';
                counter++;
            }
            else if (s[j] == '[') {
                ans += 'c';
                counter++;
            }
            else if (s[j] == '!') {
                ans += 'i';
                counter++;
            }
            else if (s[j] == ';') {
                ans += 'j';
                counter++;
            }
            else if (s[j] == '^') {
                ans += 'n';
                counter++;
            }
            else if (s[j] == '0') {
                ans += 'o';
                counter++;
            }
            else if (s[j] == '7') {
                ans += 't';
                counter++;
            }
            else {
                ans += s[j];
            }
        }

        if (counter * 2 >= ans.size()) {
            cout << "I don't understand" << '\n';
        }
        else {
            cout << ans << '\n';
        }
    }

    return 0;
}
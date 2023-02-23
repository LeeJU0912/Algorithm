#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    string s;
    getline(cin, s);

    string word;
    getline(cin, word);

    int ans = 0;

    if (s.length() >= word.length()) {
        for (int i = 0; i <= s.length() - word.length(); i++) {
            string temp = s.substr(i, word.length());
            if (temp == word) {
                i += word.length() - 1;
                ans++;
            }
        }
    }


    cout << ans;

    return 0;
}
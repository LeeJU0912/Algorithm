#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string s;
    getline(cin, s);

    string ans = "UCPC";
    int idx = 0;
    string comp;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            if (s[i] == ans[idx]) {
                idx++;
                if (idx == 4) {
                    cout << "I love UCPC";
                    return 0;
                }
            }
        }
    }

    cout << "I hate UCPC";

    return 0;
}
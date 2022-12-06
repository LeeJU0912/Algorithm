#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string s;
    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {

            if ((int)s[i] + 13 > 122) {
                s[i] = s[i] - 13;
            }
            else if ((s[i] >= 'A' && s[i] <= 'Z') && (int)s[i] + 13 > 90) {
                s[i] = s[i] - 13;
            }
            else {
                s[i] += 13;
            }
        }
    }

    cout << s;

    return 0;
}
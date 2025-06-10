#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;


int main() {
    FastIO

    string s;
    cin >> s;

    int one = 0;
    int zero = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            one++;
        }
        else if (s[i] == '0') {
            zero++;
        }
    }

    one >>= 1;
    zero >>= 1;

    vector<bool> chk(s.size());

    int counter = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            chk[i] = true;
            counter++;
        }

        if (counter == one) break;
    }

    counter = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '0') {
            chk[i] = true;
            counter++;
        }

        if (counter == zero) break;
    }

    for (int i = 0; i < s.length(); i++) {
        if (chk[i]) continue;
        cout << s[i];
    }

    return 0;
}
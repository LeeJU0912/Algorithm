#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;

    int one = 0;
    int zero = 0;

    char temp = s[0];

    if (s[0] == '0') {
        zero++;
    }
    else {
        one++;
    }


    for (int i = 1; i < s.length(); i++) {
        if (s[i] != temp) {
            if (s[i] == '0') {
                zero++;
            }
            else {
                one++;
            }
            temp = s[i];
        }
    }

    cout << min(one, zero);

    return 0;
}
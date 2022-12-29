#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string s;
    while(getline(cin, s)) {
        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') b++;
            else if (s[i] >= 'a' && s[i] <= 'z') a++;
            else if (s[i] >= '0' && s[i] <= '9') c++;
            else if (s[i] == ' ') d++;
        }

        cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    }

    return 0;
}
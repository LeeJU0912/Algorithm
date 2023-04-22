#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

char chk[10] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

int main() {
    FastIO

    string s;

    while(true) {
        getline(cin, s);

        if (s == "#") break;

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < 10; j++) {
                if (s[i] == chk[j]) ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
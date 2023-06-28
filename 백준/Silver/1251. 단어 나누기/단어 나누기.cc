#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    string s;
    cin >> s;

    string ans = s;

    sort(ans.begin(), ans.end(), greater<>());

    for (int i = 0; i < s.length() - 2; i++) {
        for (int j = i + 1; j < s.length() - 1; j++) {
            string a, b, c;

            for (int k = i; k >= 0; k--) {
                a += s[k];
            }
            for (int k = j; k > i; k--) {
                b += s[k];
            }
            for (int k = s.length() - 1; k > j; k--) {
                c += s[k];
            }

            if (a + b + c < ans) ans = a + b + c;
        }
    }

    cout << ans;

    return 0;
}
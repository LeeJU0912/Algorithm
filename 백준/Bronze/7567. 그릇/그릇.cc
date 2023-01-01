#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;

    int ans = 10;

    for (int i = 1; i < s.length(); i++) {
        if (s[i - 1] != s[i]) {
            ans += 10;
        }
        else {
            ans += 5;
        }
    }

    cout << ans;

    return 0;
}
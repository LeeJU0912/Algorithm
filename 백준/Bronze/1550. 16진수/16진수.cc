#include <bits/stdc++.h>
using namespace std;





int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string s;

    cin >> s;

    int ans = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            ans += pow(16, s.length() - 1 - i) * (s[i] - '0');
        }
        else if (s[i] >= 'A' && s[i] <= 'F') {
            ans += pow(16, s.length() - 1 - i) * (s[i] - 'A' + 10);
        }
    }

    cout << ans;

    return 0;
}
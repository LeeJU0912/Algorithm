#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    string s;
    cin >> s;

    bool isJungsu = true;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') {
            if (isJungsu) ans++;
            else isJungsu = true;
        }
        else {
            if (s[i] >= '0' && s[i] <= '9') continue;

            isJungsu = false;
        }
    }

    cout << ans + 1;

    return 0;
}
#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int cnt[26];
int maxi;

int main() {
    FastIO

    string s;
    while(cin >> s) {
        for (char i : s) {
            maxi = max(maxi, ++cnt[i - 'a']);
        }
    }

    string ans;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == maxi) ans += (char)('a' + i);
    }
    
    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
string s;
map<int, int> mp;

int ans;

int main() {
    FastIO

    cin >> N >> s;

    int len = 0;
    int idx = 0;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;

        if (mp.size() > N) {
            while(mp.size() > N) {
                mp[s[idx]]--;
                if (mp[s[idx]] == 0) {
                    mp.erase(s[idx]);
                }
                idx++;
            }
        }

        ans = max(ans, i - idx + 1);
    }

    cout << ans;

    return 0;
}
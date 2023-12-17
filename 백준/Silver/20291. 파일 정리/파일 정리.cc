#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

map<string, int> mp;

int main() {
    FastIO

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        bool chk = false;
        string ans;
        for (int j = 0; j < s.size(); j++) {
            if (chk) {
                ans += s[j];
            }
            if (s[j] == '.') chk = true;
        }

        mp[ans]++;
    }

    for (auto i : mp) {
        cout << i.first << ' ' << i.second << '\n';
    }

    return 0;
}
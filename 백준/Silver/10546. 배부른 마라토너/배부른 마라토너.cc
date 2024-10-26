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

        mp[s]++;
    }
    for (int i = 0; i < N - 1; i++) {
        string s;
        cin >> s;
        mp[s]--;
    }

    for (const auto& x : mp) {
        if (x.second) {
            cout << x.first;
            return 0;
        }
    }

    return 0;
}
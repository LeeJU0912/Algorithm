#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N, M;
    cin >> N >> M;

    map<int, string> mp;
    for (int i = 0; i < N; i++) {
        string s;
        int x;
        cin >> s >> x;

        if (!mp[x].empty()) continue;

        mp[x] = s;
    }

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;

        auto s = mp.lower_bound(x);
        cout << s->second << '\n';
    }

    return 0;
}
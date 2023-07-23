#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

int main() {
    FastIO

    cin >> N;

    map<string, int> save;

    set<char> ans;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        save[s]++;
    }

    for (auto i : save) {
        for (auto j : save) {
            if (i.first == j.first && i.second == 1) continue;
            if (i.first[0] > j.first[1]) {
                ans.insert(i.first[0]);
            }
            else {
                ans.insert(j.first[1]);
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i << ' ';
    }

    return 0;
}
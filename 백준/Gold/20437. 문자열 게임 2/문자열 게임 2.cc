#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        vector<vector<int>> save(26);

        string s;
        cin >> s;

        int n;
        cin >> n;

        for (int i = 0; i < s.size(); i++) {
            save[s[i] - 'a'].push_back(i);
        }

        int ans1 = INT_MAX;
        int ans2 = 0;
        for (int i = 0; i < 26; i++) {
            if (save[i].size() < n) continue;
            for (int j = 0; j <= save[i].size() - n; j++) {
                ans1 = min(ans1, save[i][j + n - 1] - save[i][j] + 1);
                ans2 = max(ans2, save[i][j + n - 1] - save[i][j] + 1);
            }
        }

        if (ans1 == INT_MAX && ans2 == 0) {
            cout << -1 << '\n';
        }
        else {
            cout << ans1 << ' ' << ans2 << '\n';
        }
    }

    return 0;
}
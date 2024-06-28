#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<pair<int, int>> save[26][2];

int ans = INT_MAX;

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); j++) {
            save[s[j] - 'a'][0].push_back({j, i});
            save[s[j] - 'a'][1].push_back({s.size() - j - 1, i});
        }
    }

    for (int i = 0; i < 26; i++) {
        sort(save[i][1].begin(), save[i][1].end());
    }

    for (int i = 0; i < 26; i++) {
        if (save[i][0].empty()) continue;
        if (save[i][1].empty()) continue;

        for (int x = 0; x < save[i][0].size(); x++) {
            int idx = 0;

            while(idx < save[i][0].size() && save[i][0][x].second == save[i][1][idx].second) idx++;

            if (idx == save[i][0].size()) continue;

            ans = min(ans, save[i][0][x].first + save[i][1][idx].first);
        }
    }

    cout << (ans == INT_MAX ? -1 : ans);

    return 0;
}
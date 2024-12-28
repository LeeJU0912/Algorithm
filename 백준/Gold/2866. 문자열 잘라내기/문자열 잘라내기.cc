#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int R, C;
vector<string> save;
string columns[1001];

int main() {
    FastIO

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;

        save.push_back(s);
    }
    for (int i = R - 1; i >= 0; i--) {
        for (int j = 0; j < C; j++) {
            columns[j].push_back(save[i][j]);
        }
    }

    bool chk = false;
    int ans = 0;
    for (int i = 0; i < R; i++) {
        map<string, int> cnt;

        for (int j = 0; j < C; j++) {
            columns[j].pop_back();
            cnt[columns[j]]++;
        }

        for (auto& info : cnt) {
            if (info.second >= 2) {
                ans = i;
                chk = true;
            }
        }

        if (chk) break;
    }

    cout << ans;

    return 0;
}
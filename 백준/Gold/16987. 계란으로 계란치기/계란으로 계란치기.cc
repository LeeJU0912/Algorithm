#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int ans;
int N;
vector<pair<int, int>> save;

void dfs (int idx) {
    if (idx == N) {
        int counter = 0;
        for (int i = 0; i < N; i++) {
            if (save[i].first <= 0) counter++;
        }
        ans = max(ans, counter);
        return;
    }
    bool flag = false;
    for (int i = 0; i < N; i++) {
        if (i == idx) continue;
        if (save[idx].first > 0 && save[i].first > 0) {
            save[idx].first -= save[i].second;
            save[i].first -= save[idx].second;
            dfs(idx + 1);
            save[idx].first += save[i].second;
            save[i].first += save[idx].second;
            flag = true;
        }
    }
    if (!flag) dfs(idx + 1);
}

int main() {
    FastIO


    cin >> N;

    for (int i = 0; i < N; i++) {
        int s, w;
        cin >> s >> w;
        save.emplace_back(s, w);
    }

    dfs(0);

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;

int ans = INT_MAX;

void solve(int left, int idx, int cnt) {
    if (ans < cnt) return;
    if (left == 0) {
        ans = min(ans, cnt);
        return;
    }
    for (int i = idx; i < save.size(); i++) {
        if (save[i] > left) continue;
        solve(left - save[i], i, cnt + 1);
    }
}

int main() {
    FastIO

    cin >> N;

    int before = 0;
    int cnt = 0;
    int idx = 1;
    while(cnt < N) {
        cnt += idx + before;
        before = idx + before;
        idx++;
        save.push_back(cnt);
    }

    sort(save.begin(), save.end(), greater());

    for (int i = 0; i < save.size(); i++) {
        if (save[i] > N) continue;
        solve(N - save[i], i, 1);
    }

    cout << ans << '\n';

    return 0;
}
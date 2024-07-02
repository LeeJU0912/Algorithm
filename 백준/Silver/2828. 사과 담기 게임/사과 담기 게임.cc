#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, J;
vector<int> save;

int ans;

void solve(int idx, int l, int r, int hap) {
    if (idx == J) {
        ans = hap;
        return;
    }

    if (save[idx] < l) {
        solve(idx + 1, save[idx], save[idx] + M - 1, hap + l - save[idx]);
    }
    else if (r < save[idx]) {
        solve(idx + 1, save[idx] - M + 1, save[idx], hap + save[idx] - r);
    }
    else {
        solve(idx + 1, l, r, hap);
    }
}

int main() {
    FastIO

    cin >> N >> M >> J;
    for (int i = 0; i < J; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);
    }

    solve(0, 1, M, 0);

    cout << ans;

    return 0;
}
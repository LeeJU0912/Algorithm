#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<pair<int, int>> save;

int ans = INT_MAX;

void solve(int start, int x, int y) {
    ans = min(ans, abs(x - y));

    for (int i = start + 1; i < N; i++) {
        solve(i, x * save[i].first, y + save[i].second);
    }
}

int main() {
    FastIO

    cin >> N;

    save = vector<pair<int, int>>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i].first >> save[i].second;
    }

    for (int i = 0; i < N; i++) {
        solve(i, save[i].first, save[i].second);
    }

    cout << ans;

    return 0;
}
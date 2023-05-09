#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;


int main() {
    FastIO

    int n;
    cin >> n;

    vector<pair<int, int>> save;

    for (int i = 0; i < n; i++) {
        int d, t;
        cin >> d >> t;
        save.emplace_back(t, d);
    }

    sort(save.begin(), save.end(), greater<>());

    int ans = save[0].first;
    for (int i = 0; i < n; i++) {
        ans = min(save[i].first - save[i].second, ans - save[i].second);
    }

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    vector<pair<int, int>> save;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        save.push_back({a, b});
    }

    sort(save.begin(), save.end());

    int ans = 0;
    int R = INT_MIN;
    int L = INT_MIN;

    for (int i = 0; i < N; i++) {
        if (R < save[i].first) {
            ans += R - L;
            L = save[i].first;
            R = save[i].second;
        }
        else {
            R = max(R, save[i].second);
        }
    }
    ans += R - L;

    cout << ans << '\n';

    return 0;
}
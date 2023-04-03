#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<pair<int, int>> save;

int main() {
    FastIO

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        save.push_back({b, a});
    }

    sort(save.begin(), save.end(), greater<>());

    int ans = save[0].first;

    for (int i = 0; i < N; i++) {
        ans = min(ans - save[i].second, save[i].first - save[i].second);
    }

    if (ans < 0) {
        cout << -1;
    }
    else {
        cout << ans;
    }

    return 0;
}
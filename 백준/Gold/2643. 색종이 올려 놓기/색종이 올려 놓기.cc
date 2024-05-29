#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<pair<int, int>> save;
int DP[101];

int ans;

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b) swap(a, b);

        save.push_back({a, b});
    }

    sort(save.begin(), save.end());

    for (int i = 0; i < N; i++) {
        DP[i] = max(DP[i], 1);
        for (int j = i + 1; j < N; j++) {
            if (save[i].second > save[j].second) continue;
            DP[j] = max(DP[j], DP[i] + 1);
            ans = max(ans, DP[j]);
        }
    }

    cout << ans;

    return 0;
}
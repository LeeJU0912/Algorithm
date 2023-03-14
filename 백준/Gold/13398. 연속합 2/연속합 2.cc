#include <bits/stdc++.h>
using namespace std;

int DP[100001][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> save(n);

    for (int i = 0; i < n; i++) {
        cin >> save[i];
    }

    DP[0][0] = save[0];
    DP[0][1] = 0;

    for (int i = 1; i < n; i++) {
        DP[i][0] = max(save[i], DP[i - 1][0] + save[i]);
        DP[i][1] = max(DP[i - 1][0], DP[i - 1][1] + save[i]);
    }

    int ans = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            ans = max(ans, DP[i][0]);
        }
        else {
            ans = max(ans, max(DP[i][0], DP[i][1]));
        }
    }

    cout << ans;

    return 0;
}
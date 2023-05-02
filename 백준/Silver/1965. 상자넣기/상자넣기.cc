#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int DP[1000];

int main() {
    FastIO

    int n;
    cin >> n;

    vector<int> save(n);

    for (int i = 0; i < n; i++) {
        cin >> save[i];
    }

    for (int i = 0; i < n; i++) {
        DP[i] = 1;
        for (int j = 0; j < i; j++) {
            if (save[j] < save[i]) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, DP[i]);
    }
    
    cout << ans;

    return 0;
}
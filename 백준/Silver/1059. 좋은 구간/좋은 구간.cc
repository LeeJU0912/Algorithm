#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int L;
    cin >> L;

    vector<int> save(L);

    for (int i = 0; i < L; i++) {
        cin >> save[i];
    }

    int n;
    cin >> n;

    sort(save.begin(), save.end());

    int high_idx = lower_bound(save.begin(), save.end(), n) - save.begin();
    int low_val = 0;

    for (int i = 0; i < high_idx; i++) {
        if (save[i] >= n) break;
        else low_val = save[i];
    }
    low_val++;

    int ans = 0;
    for (int i = low_val; i <= n; i++) {
        for (int j = n; j < save[high_idx]; j++) {
            if (i == j) continue;
            ans++;
        }
    }

    cout << ans;
    
    return 0;
}
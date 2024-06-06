#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    while(true) {
        int T;
        cin >> T;
        if (T == 0) break;

        vector<int> save[10000];

        int maxi = 0;

        for (int w = 0; w < T; w++) {
            int N;
            cin >> N;

            for (int i = 0; i < N; i++) {
                int x;
                cin >> x;
                save[w].push_back(x);
                maxi = max(maxi, x);
            }

            sort(save[w].begin(), save[w].end());
        }

        int ans = INT_MAX;
        for (int i = 0; i <= maxi; i++) {
            int hap = 0;

            for (int j = 0; j < T; j++) {
                int idx = lower_bound(save[j].begin(), save[j].end(), i) - save[j].begin();
                if (idx == 0 || idx == save[j].size()) {
                    hap += save[j].size();
                }
                else {
                    hap += abs((idx - 1) - ((int)save[j].size() - idx - 1));
                }
            }
            ans = min(ans, hap);
        }

        cout << ans << '\n';

    }

    return 0;
}
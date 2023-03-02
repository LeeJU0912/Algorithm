#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        vector<int> save(N);

        for (int i = 0; i < N; i++) {
            cin >> save[i];
        }

        int maxi = *max_element(save.begin(), save.end());

        vector<int> saved_max(N);
        saved_max[N - 1] = save[N - 1];

        for (int i = N - 2; i >= 0; i--) {
            saved_max[i] = max(saved_max[i + 1], save[i]);
        }

        long long ans = 0;
        for (int i = 0; i < N; i++) {
            if (save[i] < maxi) {
                ans += maxi - save[i];
            }
            else {
                if (i < N - 1) {
                    maxi = saved_max[i + 1];
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
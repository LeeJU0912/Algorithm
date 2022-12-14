#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int TC;
    cin >> TC;

    while (TC--) {
        long long ans = 0;

        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += gcd(v[i], v[j]);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
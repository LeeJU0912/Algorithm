#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long N, K, Q;

int main() {
    FastIO

    cin >> N >> K >> Q;

    for (int i = 0; i < Q; i++) {
        long long x, y;
        cin >> x >> y;

        if (K == 1) {
            cout << abs(x - y) << '\n';
            continue;
        }

        int ans = 0;

        while(x != y) {
            if (x < y) {
                y = (y - 2) / K + 1;
            }
            else {
                x = (x - 2) / K + 1;
            }

            ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}
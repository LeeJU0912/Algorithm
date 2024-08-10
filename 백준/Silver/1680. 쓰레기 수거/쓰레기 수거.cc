#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        int W, N;
        cin >> W >> N;

        long long ans = 0;
        int currentW = 0;
        int before = 0;

        for (int i = 0; i < N; i++) {
            int x, w;
            cin >> x >> w;

            ans += (x - before);
            before = x;

            if (currentW + w > W) {
                ans += x + x;
                currentW = w;
            }
            else {
                currentW += w;

                if (i < N - 1 && currentW == W) {
                    ans += x + x;
                    currentW = 0;
                }
            }

            if (i == N - 1) ans += x;
        }

        cout << ans << '\n';
    }

    return 0;
}
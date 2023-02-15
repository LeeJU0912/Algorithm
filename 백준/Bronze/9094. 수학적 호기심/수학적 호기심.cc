#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        int n, m;
        cin >> n >> m;

        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((i * i + j * j + m) % (i * j) == 0) ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
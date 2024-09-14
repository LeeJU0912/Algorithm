#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        int now = 0;
        string ans;
        for (int j = 0; j < p; j++) {
            int x;
            string y;
            cin >> x >> y;

            if (x >= now) {
                now = x;
                ans = y;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
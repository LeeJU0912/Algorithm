#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int ans = 0;


        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            int dist_start = pow(a - x1, 2) + pow(b - y1, 2);
            int dist_end = pow(a - x2, 2) + pow(b - y2, 2);
            if ((dist_start < pow(c, 2) && dist_end > pow(c, 2)) || (dist_start > pow(c, 2) && dist_end < pow(c, 2))) ans++;
        }
        
        cout << ans << '\n';
    }

    return 0;
}
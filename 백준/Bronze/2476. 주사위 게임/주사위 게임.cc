#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int ans = 0;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == b && b == c) {
            ans = max(ans, 10000 + a * 1000);
        }
        else if (a != b && b != c && c != a) {
            ans = max(ans, max(a, max(b, c)) * 100);
        }
        else {
            if (a == b) {
                ans = max(ans, 1000 + a * 100);
            }
            else if (b == c) {
                ans = max(ans, 1000 + b * 100);
            }
            else if (a == c) {
                ans = max(ans, 1000 + c * 100);
            }
        }
    }

    cout << ans;

    return 0;
}
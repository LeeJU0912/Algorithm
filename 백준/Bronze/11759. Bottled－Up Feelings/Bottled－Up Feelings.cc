#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int s, v1, v2;
    cin >> s >> v1 >> v2;

    int ans1 = 1e9;
    int ans2 = 1e9;

    for (int i = 0; v1 * i <= s; i++) {
        if ((s - (v1 * i)) % v2 == 0) {
            int one = i;
            int two = (s - (v1 * i)) / v2;

            if (ans1 + ans2 > one + two) {
                ans1 = one;
                ans2 = two;
            }
        }
    }

    if (ans1 == 1e9 && ans2 == 1e9) {
        cout << "Impossible";
    }
    else {
        cout << ans1 << ' ' << ans2;
    }

    return 0;
}
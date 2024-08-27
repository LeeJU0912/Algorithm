#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int price[4];
int cnt[101];

int main() {
    FastIO

    cin >> price[1] >> price[2] >> price[3];

    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;

        for (int j = x; j < y; j++) {
            cnt[j]++;
        }
    }

    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        ans += price[cnt[i]] * cnt[i];
    }

    cout << ans;

    return 0;
}
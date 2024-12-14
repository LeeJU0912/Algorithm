#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    int ans = 0;
    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;
        ans += min(x, N);
    }

    cout << ans;

    return 0;
}
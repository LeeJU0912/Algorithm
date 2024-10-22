#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int H, W, N, M;
    cin >> H >> W >> N >> M;

    int ans = 0;
    for (int i = 0; i < H; i += N + 1) {
        ans += (W % (M + 1) == 0 ? W / (M + 1) : W / (M + 1) + 1);
    }

    cout << ans;

    return 0;
}
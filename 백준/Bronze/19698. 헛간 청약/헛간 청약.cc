#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N, W, H, L;
    cin >> N >> W >> H >> L;

    int mini = min(N, (W / L) * (H / L));

    cout << mini;

    return 0;
}
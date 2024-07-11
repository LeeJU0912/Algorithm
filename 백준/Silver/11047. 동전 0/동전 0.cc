#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
int coin[10];
int ans;

int main() {
    FastIO

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        if (coin[i] > K) continue;
        if (K == 0) break;
        int plus = K / coin[i];

        ans += plus;

        K -= coin[i] * plus;
    }

    cout << ans;

    return 0;
}
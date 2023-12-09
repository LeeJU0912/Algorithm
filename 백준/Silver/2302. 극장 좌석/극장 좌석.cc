#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

int DP[41];
int vip[41];

long long ans = 1;

int main() {
    FastIO

    DP[0] = 1;
    DP[1] = 1;
    DP[2] = 2;

    for (int i = 3; i <= 40; i++) {
        DP[i] = DP[i - 2] + DP[i - 1];
    }

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int temp;
        cin >> temp;

        vip[i] = temp;
    }

    for (int i = 1; i <= M; i++) {
        ans *= DP[vip[i] - vip[i - 1] - 1];
    }

    ans *= DP[N - vip[M]];

    cout << ans;

    return 0;
}
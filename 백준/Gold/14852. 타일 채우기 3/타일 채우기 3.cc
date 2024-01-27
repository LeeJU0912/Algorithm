#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

#define MOD 1000000007

int N;
long long DP[1000001];
long long hap[1000001];

int main() {
    FastIO

    cin >> N;

    DP[1] = 2;
    DP[2] = 7;
    DP[3] = 22;

    hap[0] = 1;
    hap[1] = 2;

    for (int i = 4; i <= N; i++) {
        hap[i - 3] = (hap[i - 4] + DP[i - 3]) % MOD;
        DP[i] = (DP[i - 1] * 2 + DP[i - 2] * 3 + hap[i - 3] * 2) % MOD;
    }

    cout << DP[N];

    return 0;
}
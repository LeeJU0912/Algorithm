#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define MOD 1000000000

int N;

long long DP[1000001];

int main() {
    FastIO

    cin >> N;

    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 2;
    DP[4] = 4;
    DP[5] = 4;
    DP[6] = 6;
    DP[7] = 6;

    for (int i = 8; i <= N; i++) {
        i % 2 ? DP[i] = (DP[i - 1]) % MOD : DP[i] = (DP[i - 1] + DP[i / 2]) % MOD;
    }

    cout << DP[N];

    return 0;
}
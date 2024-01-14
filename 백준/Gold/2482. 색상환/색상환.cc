#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

#define MOD 1000000003;

int N, K;
int DP[1001][501];

int main() {
    FastIO

    cin >> N >> K;

    if (N / 2 < K) {
        cout << 0;
        return 0;
    }

    DP[1][1] = 1;
    DP[2][1] = 2;
    DP[3][1] = 3;
    
    for (int i = 4; i <= N; i++) {
        DP[i][1] = i;
        for (int j = 2; j <= K; j++) {
            DP[i][j] = (DP[i - 2][j - 1] + DP[i - 1][j]) % MOD;
        }
    }

    cout << DP[N][K] % MOD;

    return 0;
}
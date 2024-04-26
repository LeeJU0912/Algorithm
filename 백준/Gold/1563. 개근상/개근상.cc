#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define MOD 1000000


int N;
long long DP[1001][2][3];

int main() {
    FastIO

    cin >> N;

    DP[1][0][0] = 1;
    DP[1][1][0] = 1;
    DP[1][0][1] = 1;

    for (int i = 2; i <= N; i++) {
        DP[i][0][0] = (DP[i - 1][0][0] + DP[i - 1][0][1] + DP[i - 1][0][2]) % MOD;
        DP[i][0][1] = DP[i - 1][0][0];
        DP[i][0][2] = DP[i - 1][0][1];
        DP[i][1][0] = (DP[i - 1][0][0] + DP[i - 1][0][1] + DP[i - 1][0][2] + DP[i - 1][1][0] + DP[i - 1][1][1] + DP[i - 1][1][2]) % MOD;
        DP[i][1][1] = DP[i - 1][1][0];
        DP[i][1][2] = DP[i - 1][1][1];
    }


    cout << (DP[N][0][0] + DP[N][0][1] + DP[N][0][2] + DP[N][1][0] + DP[N][1][1] + DP[N][1][2]) % MOD;

    return 0;
}
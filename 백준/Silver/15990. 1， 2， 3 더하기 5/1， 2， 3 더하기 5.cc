#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

#define MOD 1000000009

int N;
long long DP[100001][4];

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        memset(DP, 0, sizeof(DP));
        cin >> N;

        DP[1][1] = 1;
        DP[2][2] = 1;
        DP[3][1] = 1;
        DP[3][2] = 1;
        DP[3][3] = 1;

        for (int i = 4; i <= N; i++) {
            DP[i][1] += (DP[i - 1][2] + DP[i - 1][3]) % MOD;
            DP[i][2] += (DP[i - 2][1] + DP[i - 2][3]) % MOD;
            DP[i][3] += (DP[i - 3][1] + DP[i - 3][2]) % MOD;
        }

        cout << (DP[N][1] + DP[N][2] + DP[N][3]) % MOD << '\n';
    }

    return 0;
}
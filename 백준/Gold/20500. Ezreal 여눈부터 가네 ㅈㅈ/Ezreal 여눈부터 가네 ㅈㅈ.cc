#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    int DP[3][1516];

    DP[0][1] = 0;
    DP[0][2] = 1;
    DP[1][2] = 1;
    DP[2][2] = 0;

    for (int i = 3; i <= N; i++) {
        DP[0][i] = (DP[2][i - 1] + DP[1][i - 1]) % 1000000007;
        DP[1][i] = (DP[0][i - 1] + DP[2][i - 1]) % 1000000007;
        DP[2][i] = (DP[1][i - 1] + DP[0][i - 1]) % 1000000007;
    }

    cout << DP[0][N];

    return 0;
}
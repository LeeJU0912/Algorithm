#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long DP[65][10];

int main() {
    FastIO

    for (int i = 9; i >= 0; i--) {
        DP[1][i] = 1;
    }

    for (int i = 2; i <= 64; i++) {
        for (int j = 9; j >= 0; j--) {
            DP[i][j] = DP[i - 1][j] + DP[i][j + 1];
        }
    }

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;

        long long ans = 0;
        for (int i = 0; i <= 9; i++) {
            ans += DP[n][i];
        }

        cout << ans << '\n';
    }

    return 0;
}
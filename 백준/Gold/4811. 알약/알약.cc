#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long DP[31][31];

int main() {
    FastIO

    int N;

    for (int i = 0; i <= 30; i++) {
        DP[0][i] = 1;
    }

    for (int i = 1; i <= 30; i++) {
        for (int j = 0; j <= 30; j++) {
            if (j == 0) {
                DP[i][j] += DP[i - 1][j + 1];
            }
            else {
                DP[i][j] += DP[i - 1][j + 1] + DP[i][j - 1];
            }
        }
    }

    while(true) {
        cin >> N;
        if (N == 0) break;
        
        cout << DP[N][0] << '\n';
    }

    return 0;
}
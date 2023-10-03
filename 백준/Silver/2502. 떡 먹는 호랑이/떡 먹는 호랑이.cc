#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int D, K;

int DP[31];

int main() {
    FastIO

    cin >> D >> K;

    DP[D] = K;

    for (int i = K - 1; i >= 1; i--) {
        DP[D - 1] = i;

        for (int j = D - 2; j >= 1; j--) {
            DP[j] = DP[j + 2] - DP[j + 1];
        }

        if (DP[1] <= DP[2] && DP[1] > 0 && DP[2] > 0) break;
    }
    cout << DP[1] << '\n' << DP[2];

    return 0;
}
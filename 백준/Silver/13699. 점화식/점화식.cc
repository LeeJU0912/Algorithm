#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long DP[36];

int main() {
    FastIO

    int n;
    cin >> n;



    DP[0] = 1;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 5;

    for (int i = 4; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            DP[i] += DP[j] * DP[i - 1 - j];
        }
    }

    cout << DP[n];

    return 0;
}
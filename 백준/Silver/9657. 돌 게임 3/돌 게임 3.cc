#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int DP[1001];

int main() {
    FastIO

    cin >> N;
    DP[1] = 0;
    DP[2] = 1;
    DP[3] = 0;
    DP[4] = 0;
    for (int i = 5; i <= N; i++) {
        DP[i] = !DP[i - 1] & !DP[i - 3] & !DP[i - 4];
    }

    cout << (DP[N] == 0 ? "SK" : "CY");

    return 0;
}
#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int save[5001];
int DP[5001][5001];

int solve(int l, int r) {
    if (l >= r) {
        return 0;
    }
    if (DP[l][r] != -1) {
        return DP[l][r];
    }

    if (save[l] != save[r]) {
        DP[l][r] = min(solve(l + 1, r), solve(l, r - 1)) + 1;
    }
    else {
        DP[l][r] = solve(l + 1, r - 1);
    }

    return DP[l][r];
}

int main() {
    FastIO

    memset(DP, -1, sizeof(DP));

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    cout << solve(0, N - 1);

    return 0;
}
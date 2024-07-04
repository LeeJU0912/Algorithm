#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<int> v;

int dp[100001][5][5];

int check(int from, int to) {
    if (from == 0) return 2;
    if (from == to) return 1;
    if (abs(from - to) == 2) return 4;

    return 3;
}

int solve(int idx, int left, int right) {
    if (idx == v.size()) return 0;

    int& result = dp[idx][left][right];

    if (result != -1) return result;

    int L = solve(idx + 1, v[idx], right) + check(left, v[idx]);
    int R = solve(idx + 1, left, v[idx]) + check(right, v[idx]);

    return result = min(L, R);
}

int main() {
    FastIO

    while(true) {
        int N;
        cin >> N;
        if (N == 0) break;

        v.push_back(N);
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0, 0);

    return 0;
}
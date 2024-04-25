#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
bool chk[101];

int DP[105][101];

int ans = INT_MAX;

void solve(int day, int hap, int coupon) {
    if (day > N) {
        ans = min(ans, hap);
        return;
    }
    if (chk[day]) {
        solve(day + 1, hap, coupon);
        return;
    }

    if (DP[day + 4][coupon + 2] > hap + 37000) {
        DP[day + 4][coupon + 2] = hap + 37000;
        solve(day + 5, hap + 37000, coupon + 2);
    }
    if (DP[day + 2][coupon + 1] > hap + 25000) {
        DP[day + 2][coupon + 1] = hap + 25000;
        solve(day + 3, hap + 25000, coupon + 1);
    }
    if (DP[day][coupon] > hap + 10000) {
        DP[day][coupon] = hap + 10000;
        solve(day + 1, hap + 10000, coupon);
    }

    if (coupon >= 3) {
        if (DP[day][coupon - 3] > hap) {
            DP[day][coupon - 3] = hap;
            solve(day + 1, hap, coupon - 3);
        }
    }
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        chk[temp] = true;
    }

    for (int i = 1; i <= N + 4; i++) {
        for (int j = 0; j <= 100; j++) {
            DP[i][j] = INT_MAX;
        }
    }

    solve(1, 0, 0);

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int L, R;

vector<int> order;

int ans = INT_MAX;

void solve(int left, int right, int idx, int hap) {
    if (hap >= ans) return;
    if (idx == M) {
        ans = min(ans, hap);
        return;
    }

    if (order[idx] < left) {
        solve(order[idx], right, idx + 1, hap + left - order[idx]);
    }
    else if (order[idx] > right) {
        solve(left, order[idx], idx + 1, hap + order[idx] - right);
    }
    else {
        solve(order[idx], right, idx + 1, hap + order[idx] - left);
        solve(left, order[idx], idx + 1, hap + right - order[idx]);
    }
}

int main() {
    FastIO

    cin >> N >> L >> R >> M;

    if (L > R) swap(L, R);

    for (int i = 0; i < M; i++) {
        int target;
        cin >> target;
        order.push_back(target);
    }

    solve(L, R, 0, 0);

    cout << ans;

    return 0;
}
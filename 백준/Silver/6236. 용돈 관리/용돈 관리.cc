#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> money;

bool solve(int nowN, int nowM, int left, int K) {
    if (nowN == N) {
        return true;
    }
    if (K < money[nowN]) {
        return false;
    }

    if (left < money[nowN]) {
        if (nowM == M) {
            return false;
        }
        return solve(nowN + 1, nowM + 1, K - money[nowN], K);
    }
    else {
        return solve(nowN + 1, nowM, left - money[nowN], K);
    }
}

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        money.push_back(x);
    }

    int mini = 1;
    int maxi = 1e9;
    int ans = maxi;
    while(mini <= maxi) {
        int mid = (mini + maxi) / 2;

        if (solve(0, 1, mid, mid)) {
            maxi = mid - 1;
            ans = min(ans, mid);
        }
        else {
            mini = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
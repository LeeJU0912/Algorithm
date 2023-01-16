#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    long long N;
    cin >> N;

    long long k;
    cin >> k;

    long long mini = 1;
    long long maxi = N * N;
    long long counter;
    long long ans;

    while(mini <= maxi) {
        counter = 0;
        long long mid = (mini + maxi) / 2;

        for (int i = 1; i <= N; i++) {
            counter += min(N, mid / i);
            if (i > mid) break;
        }

        if (counter >= k) {
            maxi = mid - 1;
            ans = mid;
        }
        else {
            mini = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
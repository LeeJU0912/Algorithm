#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int ans;

void solve(int counter, int now, int idx) {
    if (now == 1) {
        ans = min(ans, counter);
        return;
    }

    for (int i = idx; i > 1; i--) {
        if (now % i) continue;

        int temp = now;

        int cnt = 0;
        while(temp % i == 0) {
            temp /= i;
            cnt++;
        }

        if (cnt == 0) continue;

        solve(counter + cnt, temp, i - 1);
    }
}

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        ans = INT_MAX;

        int N;
        cin >> N;

        if (N == 1) {
            cout << 1 << '\n';
            continue;
        }

        for (int i = 9; i > 1; i--) {
            if (N % i) continue;

            int temp = N;

            int cnt = 0;
            while(temp % i == 0) {
                temp /= i;
                cnt++;
            }

            if (cnt == 0) continue;

            solve(cnt, temp, i - 1);
        }

        if (ans == INT_MAX) {
            cout << -1 << '\n';
        }
        else {
            cout << ans << '\n';
        }
    }

    return 0;
}
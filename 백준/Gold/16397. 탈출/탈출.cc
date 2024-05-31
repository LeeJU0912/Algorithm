#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, T, G;
int DP[100000];

int ans = INT_MAX;

void solve(int counter, int now) {
    if (now >= 100000) return;
    if (DP[now] <= counter) return;
    if (counter > T) return;

    DP[now] = counter;

    if (now == G) {
        ans = min(ans, DP[now]);
        return;
    }

    solve(counter + 1, now + 1);

    if (now * 2 >= 100000 || now == 0) return;

    int next = now * 2;
    int minus = 1;
    while(next >= 10) {
        next /= 10;
        minus *= 10;
    }

    solve(counter + 1, now * 2 - minus);
}

int main() {
    FastIO

    cin >> N >> T >> G;

    for (int i = 0; i < 100000; i++) {
        DP[i] = INT_MAX;
    }

    solve(0, N);

    if (ans == INT_MAX) {
        cout << "ANG";
    }
    else {
        cout << ans;
    }

    return 0;
}
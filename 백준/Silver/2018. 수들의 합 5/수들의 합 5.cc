#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

int ans;

void solve(int before, int hap) {
    if (hap == N) {
        ans++;
        return;
    }
    else if (hap > N) return;

    solve(before + 1, hap + before + 1);
}

int main() {
    FastIO

    cin >> N;

    for (int i = 1; i <= N; i++) {
        solve(i, i);
    }

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long N;
string ans;

void solve(long long hap) {
    if (hap == 0) return;

    if (hap % -2 == 0) {
        ans += '0';
        solve(hap / -2);
    }
    else {
        ans += '1';
        solve((hap - 1) / -2);
    }
}

int main() {
    FastIO

    cin >> N;

    if (N == 0) {
        cout << 0;
        return 0;
    }

    solve(N);

    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}
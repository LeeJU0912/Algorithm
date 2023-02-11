#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int n;
    cin >> n;

    int ans = 0;
    int mini = INT_MAX;

    int temp = n;
    while(true) {
        if (n % 2 == 0) {
            mini = min(mini, n);
        }
        n -= 5;
        if (n < 0) break;

    }

    ans = (temp - mini) / 5;

    if (n < 0 && mini == INT_MAX) {
        cout << -1;
    }
    else {
        if (mini == INT_MAX) {
            cout << ans;
        }
        else {
            cout << ans + mini / 2;
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

long long n, x;
char ans[5000000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> x;

    if (n > x) {
        cout << '!';
        return 0;
    }

    x -= n;
    memset(ans, 'A', n);

    for (long long i = n - 1; i >= 0; i--) {
        if (x > 25) {
            x -= 25;
            ans[i] = 'Z';
        }
        else {
            ans[i] += x;
            x = 0;
        }
    }

    if (x > 0) {
        cout << '!';
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }

    return 0;
}
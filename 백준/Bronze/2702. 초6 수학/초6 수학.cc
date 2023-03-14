#include <bits/stdc++.h>
using namespace std;

int ans;

int max_div(int x, int y) {
    if (y == 0) return x;
    if (x % y == 0) return y;
    else return max_div(y, x % y);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int a, b;
        cin >> a >> b;

        if (a > b) {
            ans = max_div(a, b);
        }
        else {
            ans = max_div(b, a);
        }

        cout << a * b / ans << ' ' << ans << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, a, b;
    cin >> N >> a >> b;

    a--;
    b--;

    int ans = 0;
    while(a != b) {
        ans++;
        a /= 2;
        b /= 2;
    }

    cout << ans;

    return 0;
}
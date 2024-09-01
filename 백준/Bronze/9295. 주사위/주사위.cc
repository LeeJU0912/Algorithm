#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int a, b;
        cin >> a >> b;
        cout << "Case " << t << ": " << a + b << '\n';
    }

    return 0;
}
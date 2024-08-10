#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        long long s, n;
        cin >> s >> n;

        for (int i = 0; i < n; i++) {
            int q, p;
            cin >> q >> p;
            s += q * p;
        }

        cout << s << '\n';
    }

    return 0;
}
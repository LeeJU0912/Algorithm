#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        int A, B, C, D, E;
        cin >> A >> B >> C >> D >> E;

        cout << fixed;
        cout.precision(2);
        cout << '$' << 350.34 * A + 230.90 * B + 190.55 * C + 125.30 * D + 180.90 * E << '\n';
    }

    return 0;
}
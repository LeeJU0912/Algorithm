#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long D, P, Q;

int main() {
    FastIO

    cin >> D >> P >> Q;

    if (D % P == 0 || D % Q == 0) {
        cout << D;
        return 0;
    }

    if (P < Q) swap(P, Q);

    long long ans = (D / P + 1) * P;

    for (int i = D / P; i >= 0; i--) {
        long long now = P * i;

        if ((D - now) % Q == 0) {
            cout << D;
            return 0;
        }

        if (ans == now + ((D - now) / Q + 1) * Q) break;

        ans = min(ans, now + ((D - now) / Q + 1) * Q);
    }

    cout << ans;

    return 0;
}
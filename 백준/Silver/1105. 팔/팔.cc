#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string L, R;

int main() {
    FastIO

    cin >> L >> R;

    if (L.size() != R.size()) {
        cout << 0;
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < L.size(); i++) {
        if (L[i] == R[i]) {
            if (L[i] == '8') ans++;
        }
        else break;
    }

    cout << ans;

    return 0;
}
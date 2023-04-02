#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int A, B;

    cin >> A >> B;

    int ans1 = -A - sqrt(A * A - B);
    int ans2 = -A + sqrt(A * A - B);

    if (ans1 == ans2) {
        cout << ans1;
    }
    else {
        cout << ans1 << ' ' << ans2;
    }

    return 0;
}
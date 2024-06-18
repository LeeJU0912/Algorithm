#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int X1, Y1, X2, Y2;

long long ans;

int main() {
    FastIO

    cin >> X1 >> Y1 >> X2 >> Y2;

    for (int i = X1; i < X2; i++) {
        if (i % 2) {
            ans += min(max(0, i - Y1), Y2 - Y1);
        }
    }

    for (int i = Y1; i < Y2; i++) {
        if (i % 2) {
            ans += min(max(0, i + 1 - X1), X2 - X1);
        }
    }

    cout << ans;

    return 0;
}
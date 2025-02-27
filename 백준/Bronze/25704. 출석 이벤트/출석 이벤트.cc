#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N, P;
    cin >> N >> P;

    int ans = P;
    if (N >= 20) {
        ans = min(ans, ((P >> 2) + (P >> 1)));
    }
    if (N >= 15) {
        ans = min(ans, P - 2000);
    }
    if (N >= 10) {
        ans = min(ans, P - (P / 10));
    }
    if (N >= 5) {
        ans = min(ans, P - 500);
    }

    cout << max(0, ans);

    return 0;
}
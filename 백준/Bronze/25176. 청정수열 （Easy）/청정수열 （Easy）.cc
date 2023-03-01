#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    int ans = 1;

    for (int i = N; i > 1; i--) {
        ans *= i;
    }

    cout << ans;

    return 0;
}
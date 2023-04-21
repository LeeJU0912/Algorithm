#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int ans = 0;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        ans += b % a;
    }

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    int ans = 1;
    int plus = 4;
    for (int i = 1; i <= N; i++) {
        ans += plus;
        plus += 3;
        ans %= 45678;
    }

    cout << ans;

    return 0;
}
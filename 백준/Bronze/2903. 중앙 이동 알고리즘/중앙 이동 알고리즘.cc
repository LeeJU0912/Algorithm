#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    long long ans = 2;

    for (int i = 0; i < N; i++) {
        ans += ans - 1;
    }

    cout << ans * ans;

    return 0;
}
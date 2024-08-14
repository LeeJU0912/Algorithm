#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    long long a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);

    cout << max(0LL, b - a - 1) << '\n';
    for (long long i = a + 1; i < b; i++) {
        cout << i << ' ';
    }

    return 0;
}
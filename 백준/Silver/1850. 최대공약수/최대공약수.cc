#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long A, B;

int main() {
    FastIO

    cin >> A >> B;

    int count = gcd(A, B);

    string ans;

    for (int i = 0; i < count; i++) {
        ans += '1';
    }

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;



int main() {
    FastIO

    int a, b, c, N;
    cin >> a >> b >> c >> N;

    bool ans = false;

    if (N % a == 0 || N % b == 0 || N % c == 0) {
        ans = true;
    }
    else if (N % gcd(a, b) == 0 || N % gcd(a, c) == 0 || N % gcd(b, c) == 0 || N % gcd(a, gcd(b, c)) == 0) {
        ans = true;
    }

    cout << ans;

    return 0;
}
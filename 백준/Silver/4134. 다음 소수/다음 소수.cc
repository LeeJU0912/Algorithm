#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

bool chk(long long n) {
    if (n <= 1) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    FastIO

    int t;
    cin >> t;

    while(t--) {
        long long n;
        cin >> n;

        while(!chk(n)) n++;

        cout << n << '\n';
    }

    return 0;
}
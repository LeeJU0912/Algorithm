#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

#define MOD 1000000007

long long A, X;

map<long long, long long> preCalc;

void multiply(long long now, long long val) {
    if (now > X) return;

    preCalc[now] = val;

    multiply(now * 2, (val * val) % MOD);
}

int main() {
    FastIO

    cin >> A >> X;

    multiply(1, A % MOD);

    long long ans = 1;
    long long multi = 1;
    while(X) {
        if (X & 1) {
            ans *= preCalc[multi];
            ans %= MOD;
        }
        X >>= 1;
        multi <<= 1;
    }

    cout << ans;

    return 0;
}
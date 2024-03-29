#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long n, m;

int main() {
    FastIO

    cin >> n >> m;

    long long two = 0;
    long long five = 0;

    for (long long i = 2; i <= n; i *= 2) {
        two += n / i;
    }
    for (long long i = 2; i <= (n - m); i *= 2) {
        two -= (n - m) / i;
    }
    for (long long i = 2; i <= m; i *= 2) {
        two -= m / i;
    }

    for (long long i = 5; i <= n; i *= 5) {
        five += n / i;
    }
    for (long long i = 5; i <= (n - m); i *= 5) {
        five -= (n - m) / i;
    }
    for (long long i = 5; i <= m; i *= 5) {
        five -= m / i;
    }

    cout << min(two, five);

    return 0;
}
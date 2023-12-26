#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long fibo[2000001];

int main() {
    FastIO

    int n;
    cin >> n;

    fibo[1000000] = 0;
    fibo[1000001] = 1;

    if (n < 0) {
        for (int i = -1; i >= n; i--) {
            fibo[1000000 + i] = (fibo[1000000 + i + 2] - fibo[1000000 + i + 1]) % 1000000000;
        }
    }
    else {
        for (int i = 2; i <= n; i++) {
            fibo[1000000 + i] = (fibo[1000000 + i - 2] + fibo[1000000 + i - 1]) % 1000000000;
        }
    }

    if (fibo[1000000 + n] > 0) {
        cout << 1;
    }
    else if (fibo[1000000 + n] == 0) {
        cout << 0;
    }
    else {
        cout << -1;
    }

    cout << '\n';
    cout << abs(fibo[1000000 + n] % 1000000000);

    return 0;
}
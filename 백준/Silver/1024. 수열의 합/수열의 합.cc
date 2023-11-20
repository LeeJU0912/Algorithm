#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, L;

int main() {
    FastIO

    cin >> N >> L;

    for (int i = L; i <= 100; i++) {
        int t = i * (i - 1) / 2;

        int x = (N - t) / i;

        if ((N - t) % i == 0 && x >= 0) {
            for (int j = 0; j < i; j++) {
                cout << x + j << ' ';
            }
            return 0;
        }
    }

    cout << -1;

    return 0;
}
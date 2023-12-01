#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;

int main() {
    FastIO

    cin >> N >> K;

    int hap = 0;

    for (int i = 1; i <= K; i++) {
        hap += i;
    }

    if (hap > N) {
        cout << -1;
    }
    else {
        if ((N - hap) % K) {
            cout << K;
        }
        else {
            cout << K - 1;
        }
    }

    return 0;
}
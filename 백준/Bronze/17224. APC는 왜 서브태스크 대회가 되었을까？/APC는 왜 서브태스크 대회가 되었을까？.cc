#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N, L, K;
    cin >> N >> L >> K;
    
    int hard = 0;
    int easy = 0;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        if (b <= L) {
            hard++;
        }
        else if (a <= L) {
            easy++;
        }
    }

    if (hard <= K) {
        cout << hard * 140 + min(K - hard, easy) * 100;
    }
    else {
        cout << K * 140;
    }

    return 0;
}
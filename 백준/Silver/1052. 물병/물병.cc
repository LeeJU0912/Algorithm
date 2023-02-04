#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    if (N <= K) {
        cout << 0 << '\n';
        return 0;
    }

    int plusBottle = 0;

    while(true) {
        int now = N;
        int counter = 0;
        while(now > 0) {
            if (now & 1) {
                counter++;
            }
            now /= 2;
        }
        if (counter <= K) break;
        N++;
        plusBottle++;
    }



    cout << plusBottle << '\n';

    return 0;
}
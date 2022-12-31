#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, F;
    cin >> N >> F;

    N /= 100;
    N *= 100;
    for (int i = 0; i <= 99; i++) {
        if ((N + i) % F == 0) {
            if (i < 10) {
                cout << 0 << i;
            }
            else {
                cout << i;
            }
            break;
        }
    }

    return 0;
}
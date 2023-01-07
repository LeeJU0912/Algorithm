#include <bits/stdc++.h>
using namespace std;

bool net[1000001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


    net[1] = true;
    for (int i = 2; i <= 500000; i++) {
        for (int j = 2; i * j <= 1000000; j++) {
            if (net[i * j]) continue;
            net[i * j] = true;
        }
    }

    while(true) {
        int N;
        cin >> N;
        if (N == 0) break;

        bool chk = false;
        for (int i = 3; i < N; i += 2) {
            if (!net[i] && !net[N - i]) {
                cout << N << " = " << i << " + " << N - i << '\n';
                chk = true;
                break;
            }
        }

        if (!chk) {
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }

    return 0;
}
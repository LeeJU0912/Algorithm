#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    long long N;
    cin >> N;

    if (N == 1) {
        cout << 4;
        return 0;
    }
    else if (N == 2) {
        cout << 6;
        return 0;
    }
    else if (N == 3) {
        cout << 10;
        return 0;
    }

    vector<long long> save(N);

    save[0] = 1;
    save[1] = 1;

    for (int i = 2; i < N; i++) {
        save[i] = save[i - 1] + save[i - 2];
    }

    cout << save[N - 1] * 3 + save[N - 2] * 2 + save[N - 3] * 2 + save[N - 4];

    return 0;
}
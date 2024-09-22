#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, Q;
int imos[1000001];

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        int S, E;
        cin >> S >> E;
        imos[S]++;
        imos[E + 1]--;
    }

    for (int i = 1; i <= 1000000; i++) {
        imos[i] += imos[i - 1];
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;

        cout << imos[t] << '\n';
    }

    return 0;
}
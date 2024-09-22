#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int save[100001];
int imos[100001];

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> save[i];
    }

    for (int i = 0; i < M; i++) {
        int S, E, K;
        cin >> S >> E >> K;
        imos[S] += K;
        imos[E + 1] -= K;
    }

    for (int i = 1; i <= 100000; i++) {
        imos[i] += imos[i - 1];
    }

    for (int i = 1; i <= N; i++) {
        cout << save[i] + imos[i] << ' ';
    }

    return 0;
}
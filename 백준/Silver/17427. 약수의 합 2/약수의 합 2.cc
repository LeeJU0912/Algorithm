#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
long long f[1000001];
long long g[1000001];

int main() {
    FastIO

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; i * j <= N; j++) {
            f[i * j] += i;
        }
    }

    for (int i = 1; i <= N; i++) {
        g[i] += g[i - 1] + f[i];
    }

    cout << g[N];

    return 0;
}
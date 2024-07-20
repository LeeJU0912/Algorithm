#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N, M, K;
    cin >> N >> M >> K;

    cout << min(K, M) + min(N - K, N - M);

    return 0;
}
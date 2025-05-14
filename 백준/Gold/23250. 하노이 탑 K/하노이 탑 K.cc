#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

unsigned long long K;
unsigned long long cnt;

void hanoi(int n, int from, int by, int to) {
    if (n == 0) return;
    if (cnt > K) return;
    if (cnt + (1ULL << n) - 1 < K) {
        cnt += (1ULL << n) - 1;
        return;
    }

    hanoi(n - 1, from, to, by);
    if (++cnt == K) {
        cout << from << ' ' << to;
    }

    hanoi(n - 1, by, from, to);
}

int main() {
    FastIO

    int N;
    cin >> N >> K;

    hanoi(N, 1, 2, 3);

    return 0;
}
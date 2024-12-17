#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int R, C, N;
    cin >> R >> C >> N;

    long long maxX = R % N == 0 ? R / N : R / N + 1;
    long long maxY = C % N == 0 ? C / N : C / N + 1;

    cout << maxX * maxY;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, T, C, P;

int main() {
    FastIO

    cin >> N >> T >> C >> P;
    cout << (N % T == 0 ? N / T - 1 : N / T) * C * P;

    return 0;
}
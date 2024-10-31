#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, S;
vector<int> A;

int main() {
    FastIO

    cin >> N >> S;
    A = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> gap = vector<int>(N);

    for (int i = 0; i < N; i++) {
        gap[i] = abs(S - A[i]);
    }

    int ans = gap[0];

    for (int i = 1; i < N; i++) {
        ans = gcd(ans, gap[i]);
    }

    cout << ans;

    return 0;
}
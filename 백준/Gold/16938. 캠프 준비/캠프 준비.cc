#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, L, R, X;
vector<int> A;

int ans;

void solve(int idx, int hap, int maxi, int mini, int counter) {
    if (idx == N) {
        if (counter == 0) return;
        if (L <= hap && hap <= R && maxi - mini >= X) ans++;
        return;
    }
    solve(idx + 1, hap + A[idx], max(maxi, A[idx]), min(mini, A[idx]),counter + 1);
    solve(idx + 1, hap, maxi, mini, counter);
}

int main() {
    FastIO

    cin >> N >> L >> R >> X;
    A = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    solve(0, 0, 0, INT_MAX, 0);

    cout << ans;

    return 0;
}
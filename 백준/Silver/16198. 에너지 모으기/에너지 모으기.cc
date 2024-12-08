#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> W;
bool erased[10];

int ans;

int findLeftIdx(int idx) {
    for (int i = idx - 1; i >= 0; i--) {
        if (!erased[i]) return i;
    }
    return 0;
}

int findRightIdx(int idx) {
    for (int i = idx + 1; i < N; i++) {
        if (!erased[i]) return i;
    }
    return N - 1;
}

void solve(int counter, int tmp) {
    if (counter == N - 2) {
        ans = max(ans, tmp);
        return;
    }

    for (int i = 1; i < N - 1; i++) {
        if (erased[i]) continue;

        int l = findLeftIdx(i);
        int r = findRightIdx(i);

        erased[i] = true;
        solve(counter + 1, tmp + W[l] * W[r]);
        erased[i] = false;
    }
}

int main() {
    FastIO

    cin >> N;
    W = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }

    for (int i = 1; i < N - 1; i++) {
        erased[i] = true;
        solve(1, W[i - 1] * W[i + 1]);
        erased[i] = false;
    }

    cout << ans;

    return 0;
}
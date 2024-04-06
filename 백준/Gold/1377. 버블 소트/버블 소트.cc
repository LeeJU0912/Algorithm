#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<pair<int, int>> A;

int main() {
    FastIO

    int N;
    cin >> N;

    A = vector<pair<int, int>>(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());

    int ans = -1;
    for (int i = 0; i < N; i++) {
        if (ans < A[i].second - i) ans = A[i].second - i;
    }

    cout << ans + 1;

    return 0;
}
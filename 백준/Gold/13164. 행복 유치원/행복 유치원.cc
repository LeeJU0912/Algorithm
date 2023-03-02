#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
vector<int> save;

int main() {
    FastIO

    cin >> N >> K;

    save = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    vector<long long> gap(N - 1);

    for (int i = 0; i < N - 1; i++) {
        gap[i] = save[i + 1] - save[i];
    }

    sort(gap.begin(), gap.end(), greater());


    cout << accumulate(gap.begin(), gap.end(), 0LL) - accumulate(gap.begin(), gap.begin() + K - 1, 0LL);

    return 0;
}
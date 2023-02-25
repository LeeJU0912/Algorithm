#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;
    int K;
    cin >> K;

    vector<int> save(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    sort(save.begin(), save.end());

    vector<int> DP(N - 1);

    for (int i = 0; i < N - 1; i++) {
        DP[i] = save[i + 1] - save[i];
    }

    sort(DP.begin(), DP.end());

    int ans = 0;
    for (int i = 0; i < N - K; i++) {
        ans += DP[i];
    }

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N, K;
    cin >> N >> K;

    vector<tuple<int, int, int>> save;

    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        save.push_back({b, c, d});
    }

    sort(save.begin(), save.end(), greater<>());

    int ans = 1;

    for (int i = 1; i < K; i++) {
        if (save[i - 1] != save[i]) ans++;
    }

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    vector<int> save(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    int ans = 0;

    for (int i = N - 1; i > 0; i--) {
        if (save[i] <= save[i - 1]) {
            ans += save[i - 1] - save[i] + 1;
            save[i - 1] = save[i] - 1;
        }
    }

    cout << ans;

    return 0;
}
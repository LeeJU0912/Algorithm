#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N, M;
    cin >> N >> M;

    vector<int> save(M);
    for (int i = 0; i < M; i++) {
        cin >> save[i];
    }

    sort(save.begin(), save.end());

    int ans = 0;
    int ans2 = 0;
    for (int i = 0; i < M; i++) {
        if (ans < save[i] * min(N, (M - i))) {
            ans = save[i] * min(N, (M - i));
            ans2 = save[i];
        }
    }

    cout << ans2 << ' ' << ans;

    return 0;
}
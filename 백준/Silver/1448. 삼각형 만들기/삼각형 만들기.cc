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

    sort(save.begin(), save.end());

    int ans = -1;

    for (int i = save.size() - 1; i >= 2; i--) {
        if (save[i - 1] + save[i - 2] > save[i]) {
            ans = save[i - 1] + save[i - 2] + save[i];
            break;
        }
    }

    cout << ans;

    return 0;
}
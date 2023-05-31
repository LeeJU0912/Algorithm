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

    int ans = 1;
    int count = save[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        if (save[i] > count) {
            ans++;
            count = save[i];
        }
    }

    cout << ans;

    return 0;
}
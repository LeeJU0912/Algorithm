#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N, S;
    cin >> N >> S;

    vector<int> save(N);
    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (save[i] + save[j] <= S) ans++;
        }
    }

    cout << ans;

    return 0;
}
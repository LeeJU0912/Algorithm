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

    int now = save[0];
    int counter = 0;
    int ans = 0;
    for (int i = 1; i < N; i++) {
        if (save[i] < now) {
            counter++;
        }
        else {
            ans = max(ans, counter);
            counter = 0;
            now = save[i];
        }
    }
    ans = max(ans, counter);

    cout << ans;

    return 0;
}
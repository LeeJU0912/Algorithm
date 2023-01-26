#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    long long ans = 0;
    int N;
    cin >> N;

    vector<int> save(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    sort(save.begin(), save.end());

    int counter = 1;
    for (int i = 0; i < N; i++) {
        if (save[i] != counter) {
            ans += abs(save[i] - counter);
        }
        counter++;
    }

    cout << ans;

    return 0;
}
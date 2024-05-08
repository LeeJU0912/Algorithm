#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;

long long ans;

void pick(int idx, int count, int hap) {
    if (count == 2) {
        if (binary_search(save.begin() + idx, save.end(), -hap)) {
            ans += upper_bound(save.begin() + idx, save.end(), -hap) - lower_bound(save.begin() + idx, save.end(), -hap);
        }

        return;
    }

    for (int i = idx; i < N; i++) {
        pick(i + 1, 2, hap + save[i]);
    }
}

int main() {
    FastIO

    cin >> N;
    save = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    sort(save.begin(), save.end());

    for (int i = 0; i < N; i++) {
        pick(i + 1, 1, save[i]);
    }

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;

int main() {
    FastIO

    cin >> N;
    save = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    sort(save.begin(), save.end());

    int ans = 1;
    for (int i = 0; i < N; i++) {
        if (save[i] > ans) break;
        ans += save[i];
    }

    cout << ans;

    return 0;
}
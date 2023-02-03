#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int n;
    cin >> n;

    vector<int> save(n);

    for (int i = 0; i < n; i++) {
        cin >> save[i];
    }

    sort(save.begin(), save.end());

    int ans = 0;

    for (int i = 0; i < n - 1; i++) {
        ans += save[i] + save[n - 1];
    }

    cout << ans;


    return 0;
}
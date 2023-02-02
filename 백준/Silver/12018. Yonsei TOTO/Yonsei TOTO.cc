#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int n, m;
    cin >> n >> m;


    int ans = 0;
    vector<int> mini;

    for (int i = 1; i <= n; i++) {
        vector<int> save;

        int a, b;
        cin >> a >> b;

        for (int j = 0; j < a; j++) {
            int temp;
            cin >> temp;
            save.push_back(temp);
        }

        if (a < b) {
            mini.push_back(1);
            continue;
        }
        sort(save.begin(), save.end(), greater<>());
        mini.push_back(save[b - 1]);
    }

    sort(mini.begin(), mini.end());

    for (int i = 0; i < mini.size(); i++) {
        m -= mini[i];
        if (m < 0) break;
        ans++;
    }

    cout << ans;

    return 0;
}
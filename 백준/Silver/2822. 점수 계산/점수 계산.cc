#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int ans = 0;
    vector<int> save;
    vector<int> save2;
    for (int i = 0; i < 8; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);
        save2.push_back(temp);
    }
    sort(save.begin(), save.end(), greater<>());

    vector<int> great;
    for (int i = 0; i < 5; i++) {
        great.push_back(save[i]);
        ans += save[i];
    }

    cout << ans << '\n';

    int counter = 0;
    for (int i = 0; i < 8; i++) {
        if (save2[i] >= great[4] && save2[i] <= great[0]) {
            cout << i + 1 << ' ';
        }
    }

    return 0;
}
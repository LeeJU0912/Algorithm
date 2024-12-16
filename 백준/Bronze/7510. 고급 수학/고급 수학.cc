#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        vector<int> save(3);
        for (int j = 0; j < 3; j++) {
            cin >> save[j];
        }
        sort(save.begin(), save.end());

        cout << "Scenario #" << i << ":" << '\n';
        if (save[0] * save[0] + save[1] * save[1] == save[2] * save[2]) {
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }
        cout << '\n';
    }

    return 0;
}
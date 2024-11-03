#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    vector<int> save(4);
    for (int i = 0; i < 4; i++) {
        cin >> save[i];
    }

    sort(save.begin(), save.end());

    cout << save[0] * save[2];

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int save[5];
    for (int &i : save) {
        cin >> i;
    }

    cout << min(save[4] * save[0], max(0, (save[4] - save[2])) * save[3] + save[1]);

    return 0;
}
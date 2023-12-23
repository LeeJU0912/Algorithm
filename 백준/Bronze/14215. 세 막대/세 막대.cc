#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<int> save;

int main() {
    FastIO

    for (int i = 0; i < 3; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);
    }

    sort(save.begin(), save.end());

    cout << save[0] + save[1] + min(save[2], (save[0] + save[1] - 1));

    return 0;
}
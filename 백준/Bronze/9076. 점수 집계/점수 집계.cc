#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        vector<int> save = vector<int>(5);
        for (int i = 0; i < 5; i++) {
            cin >> save[i];
        }

        sort(save.begin(), save.end());

        if (save[3] - save[1] >= 4) {
            cout << "KIN" << '\n';
        }
        else {
            int hap = 0;
            for (int i = 1; i < 4; i++) {
                hap += save[i];
            }

            cout << hap << '\n';
        }
    }

    return 0;
}
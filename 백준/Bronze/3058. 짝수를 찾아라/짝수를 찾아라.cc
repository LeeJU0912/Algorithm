#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        int mini = INT_MAX;
        int hap = 0;

        for (int i = 0; i < 7; i++) {
            int temp;
            cin >> temp;
            if (temp % 2 == 0) {
                mini = min(mini, temp);
                hap += temp;
            }
        }

        cout << hap << ' ' << mini << '\n';
    }

    return 0;
}
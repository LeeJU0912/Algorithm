#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        int N;
        string a, b;
        cin >> N >> a >> b;

        int wCount = 0;
        int bCount = 0;

        for (int i = 0; i < N; i++) {
            if (a[i] != b[i]) {
                if (a[i] == 'B') bCount++;
                else wCount++;
            }
        }

        int same = min(bCount, wCount);
        int left = wCount - same + bCount - same;

        cout << same + left << '\n';
    }

    return 0;
}
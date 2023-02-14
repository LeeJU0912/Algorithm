#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int H, Y;
    cin >> H >> Y;

    int save[11];

    save[0] = H;

    for (int i = 1; i <= Y; i++) {
        save[i] = save[i - 1] * 1.05;
        if (i >= 3) {
            save[i] = max(save[i], (int)(save[i - 3] * 1.2));
        }
        if (i >= 5) {
            save[i] = max(save[i], (int)(save[i - 5] * 1.35));
        }
    }

    cout << save[Y];

    return 0;
}
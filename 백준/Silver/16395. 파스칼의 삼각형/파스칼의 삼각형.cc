#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int n, k;
    cin >> n >> k;

    int save[31][31];

    save[1][1] = 1;
    save[2][1] = 1;
    save[2][2] = 1;

    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i) {
                save[i][j] = 1;
            }
            else {
                save[i][j] = save[i - 1][j - 1] + save[i - 1][j];
            }
        }
    }

    cout << save[n][k];

    return 0;
}
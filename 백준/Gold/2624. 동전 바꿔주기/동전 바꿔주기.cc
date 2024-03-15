#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int T, k;
long long DP[10001][101];
pair<int, int> save[101];

int main() {
    FastIO

    cin >> T >> k;
    for (int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;

        save[i] = {a, b};
    }

    DP[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= save[i].second; j++) {
            for (int x = 0; x <= T; x++) {
                if (save[i].first * j + x > T) break;
                DP[x + save[i].first * j][i] += DP[x][i - 1];
            }
        }
    }

    cout << DP[T][k];

    return 0;
}
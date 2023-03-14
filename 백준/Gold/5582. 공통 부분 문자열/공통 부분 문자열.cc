#include <bits/stdc++.h>
using namespace std;

int DP[4001][4001];
int ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string a, b;

    cin >> a >> b;

    for (int i = 0; i < b.length(); i++) {
        for (int j = 0; j < a.length(); j++) {
            if (i == 0) {
                if (b[i] == a[j]) {
                    DP[i][j] = 1;
                    ans = 1;
                }
            }
            else {
                if (b[i] == a[j]) {
                    DP[i][j] += DP[i - 1][j - 1] + 1;
                    ans = max(ans, DP[i][j]);
                }
            }
        }
    }

    cout << ans;

    return 0;
}
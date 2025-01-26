#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string a, b;
int DP[1001][1001];

int main() {
    FastIO

    cin >> a >> b;

    for (int i = 0; i <= a.size(); i++) {
        DP[i][0] = i;
    }
    for (int i = 0; i <= b.size(); i++) {
        DP[0][i] = i;
    }

    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1]) {
                DP[i][j] = DP[i - 1][j - 1];
            }
            else {
                DP[i][j] = min(DP[i - 1][j - 1], min(DP[i - 1][j], DP[i][j - 1])) + 1;
            }
        }
    }

    cout << DP[a.size()][b.size()];

    return 0;
}
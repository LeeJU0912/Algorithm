#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m;
vector<int> save1, save2;
int DP[1001][1001];

int main() {
    FastIO

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        save1.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        save2.push_back(x);
    }

    sort(save1.begin(), save1.end());
    sort(save2.begin(), save2.end());

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j) {
                DP[i][j] = DP[i - 1][j - 1] + abs(save1[i - 1] - save2[j - 1]);
            }
            else if (i > j) {
                DP[i][j] = min(DP[i - 1][j], DP[i - 1][j - 1] + abs(save1[i - 1] - save2[j - 1]));
            }
            else if (i < j) {
                DP[i][j] = min(DP[i][j - 1], DP[i - 1][j - 1] + abs(save1[i - 1] - save2[j - 1]));
            }
        }
    }

    cout << DP[n][m];

    return 0;
}
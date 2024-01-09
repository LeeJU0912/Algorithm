#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int score[2][100001];
int DP[2][100001];

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        for (int j = 0; j < 2; j++) {
            for (int i = 1; i <= n; i++) {
                cin >> score[j][i];
            }
        }

        DP[0][1] = score[0][1];
        DP[1][1] = score[1][1];
        for (int i = 2; i <= n; i++) {
            DP[0][i] = max(DP[0][i - 2], max(DP[1][i - 2], DP[1][i - 1])) + score[0][i];
            DP[1][i] = max(DP[1][i - 2], max(DP[0][i - 2], DP[0][i - 1])) + score[1][i];
        }

        cout << max(DP[0][n], DP[1][n]) << '\n';
    }

    return 0;
}
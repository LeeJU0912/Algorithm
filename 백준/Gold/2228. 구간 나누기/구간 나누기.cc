#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int save[101];
int hap[101];
int DP[101][51];

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> save[i];
        hap[i] = hap[i - 1] + save[i];
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            DP[i][j] = -1e9;
        }
    }

    for (int i = 1; i <= N; i++) {
        DP[i][1] = max(DP[i - 1][1], 0) + save[i];
    }

    for (int i = 2; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k < j - 1; k++) {
                int maxi = INT_MIN;
                for (int l = 1; l <= k; l++) {
                    maxi = max(maxi, DP[l][i - 1]);
                }
                DP[j][i] = max(DP[j][i], maxi + hap[j] - hap[k + 1]);
            }
        }
    }

    int ans = INT_MIN;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, DP[i][M]);
    }

    cout << ans;

    return 0;
}
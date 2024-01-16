#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
pair<int, int> save[1001];
int DP[1001][10001];

int main() {
    FastIO

    cin >> N >> K;

    for (int i = 1; i <= K; i++) {
        cin >> save[i].first >> save[i].second;
    }

    for (int i = 1; i <= K; i++) {
        for (int j = 0; j <= N; j++) {
            if (j - save[i].second < 0) {
                DP[i][j] = DP[i - 1][j];
                continue;
            }
            DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - save[i].second] + save[i].first);
        }
    }

    cout << DP[K][N];

    return 0;
}
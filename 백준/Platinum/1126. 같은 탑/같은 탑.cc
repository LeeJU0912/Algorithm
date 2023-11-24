#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int save[51];
int DP[51][500001];

void solve() {
    for (int i = 1; i <= 500000; i++) {
        DP[0][i] = INT_MIN;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 500000; j++) {
            // 이번 idx 안 쌓기
            DP[i][j] = DP[i - 1][j];

            // 이번 idx 큰 쪽에 쌓기
            if (save[i] <= j && DP[i - 1][j - save[i]] != INT_MIN) {
                DP[i][j] = max(DP[i][j], DP[i - 1][j - save[i]] + save[i]);
            }
            // 이번 idx 작은 쪽에 쌓기
            // 1. 작은쪽에 쌓았더니 더 길어진 경우
            if (save[i] > j && DP[i - 1][save[i] - j] != INT_MIN) {
                DP[i][j] = max(DP[i][j], j + DP[i - 1][save[i] - j]);
            }
            // 2. 쌓아도 여전히 작은 경우
            if (j + save[i] <= 500000 && DP[i - 1][j + save[i]] != INT_MIN) {
                DP[i][j] = max(DP[i][j], DP[i - 1][j + save[i]]);
            }
        }
    }
}

int main() {
    FastIO

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> save[i];
    }

    if (N == 1) {
        cout << -1;
        return 0;
    }

    solve();

    if (DP[N][0]) {
        cout << DP[N][0];
    }
    else {
        cout << -1;
    }

    return 0;
}
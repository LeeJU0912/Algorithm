#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, T;
bool hole[101][21];
int DP[101][21];

int main() {
    FastIO

    cin >> N >> T;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 20; j++) {
            DP[i][j] = 1e9;
        }
    }

    for (int i = 1; i <= N; i++) {
        int M;
        cin >> M;

        for (int j = 0; j < M; j++) {
            int temp;
            cin >> temp;
            hole[i][temp] = true;
        }
    }

    for (int i = 0; i <= 20; i++) {
        if (hole[1][i]) {
            if (i <= 2) {
                DP[1][i] = 0;
            }
            else {
                DP[1][i] = 1;
            }
        }
    }

    hole[0][1] = true;
    DP[0][1] = 0;


    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 20; j++) {
            if (!hole[i][j]) continue;

            if (hole[i + 1][j]) DP[i + 1][j] = min(DP[i + 1][j], DP[i][j]);
            if (hole[i + 1][j + 1]) DP[i + 1][j + 1] = min(DP[i + 1][j + 1], DP[i][j]);
            if (hole[i + 1][j - 1]) DP[i + 1][j - 1] = min(DP[i + 1][j - 1], DP[i][j]);
            if (hole[i + 1][min(20, j * 2)]) DP[i + 1][(min(20, j * 2))] = min(DP[i + 1][min(20, j * 2)], DP[i][j]);
            for (int k = 0; k <= 20; k++) {
                if (hole[i + 1][k]) DP[i + 1][k] = min(DP[i + 1][k], DP[i][j] + 1);
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i <= 20; i++) {
        ans = min(ans, DP[N][i]);
    }

    if (ans <= T) {
        cout << ans;
    }
    else {
        cout << -1;
    }

    return 0;
}
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, T;

vector<pair<int, int>> save;

int DP[101][10001];

int main() {
    FastIO

    cin >> N >> T;

    for (int i = 0; i < N; i++) {
        int K, S;

        cin >> K >> S;
        save.emplace_back(K, S);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= T; j++) {
            if (j - save[i].first >= 0) {
                DP[i + 1][j] = max(DP[i][j], DP[i][j - save[i].first] + save[i].second);
            }
            else {
                DP[i + 1][j] = DP[i][j];
            }
        }
    }

    cout << DP[N][T];

    return 0;
}